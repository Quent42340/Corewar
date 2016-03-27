/*
 * =====================================================================================
 *
 *       Filename:  SideBar.cpp
 *
 *    Description:  
 *
 *        Created:  27/03/2016 15:21:47
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <QCheckBox>
#include <QFileDialog>
#include <QFormLayout>

#include "CorewarRenderer.hpp"
#include "GLWidget.hpp"
#include "MainWindow.hpp"
#include "MediaPlayer.hpp"
#include "PlayerWidget.hpp"
#include "SideBar.hpp"

SideBar::SideBar(MediaPlayer *mediaPlayer, GLWidget *glWidget, QWidget *parent) : QWidget(parent) {
	m_mediaPlayer = mediaPlayer;
	m_glWidget = glWidget;
	
	setMinimumSize(MainWindow::width / 5, 0);
	
	m_layout = new QVBoxLayout(this);
	
	initMusicPlayerWidgets();
	initYoutubeWidgets();
	initLocalMusicWidgets();
	initSettingsWidgets();
	
	connect(m_youtubeVideoButton, SIGNAL(pressed()), this, SLOT(downloadYoutubeMusic()));
	connect(m_mediaPlayer, SIGNAL(downloadFinished()), this, SLOT(downloadFinished()));
	connect(m_mediaPlayer, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(downloadProgress(qint64, qint64)));
}

void SideBar::initMusicPlayerWidgets() {
	QGroupBox *musicBox = new QGroupBox("Now playing", this);
	QHBoxLayout *layout = new QHBoxLayout(musicBox);
	
	QLabel *youtubeVideoNameLabel = new QLabel(musicBox);
	youtubeVideoNameLabel->setWordWrap(true);
	
	layout->addWidget(youtubeVideoNameLabel);
	m_layout->addWidget(musicBox);
	
	connect(m_mediaPlayer, SIGNAL(musicChanged(const QString &)), youtubeVideoNameLabel, SLOT(setText(const QString &)));
}

void SideBar::initYoutubeWidgets() {
	QGroupBox *youtubeBox = new QGroupBox("YouTube", this);
	m_youtubeVideoButton = new QPushButton("Download and play", youtubeBox);
	
	m_youtubeVideoIDWidget = new QLineEdit("7eZIbmq5Jiw", youtubeBox);
	
	m_downloadProgressBar = new QProgressBar(youtubeBox);
	m_downloadProgressBar->setRange(0, 100);
	m_downloadProgressBar->setVisible(false);
	
	QFormLayout *layout = new QFormLayout(youtubeBox);
	layout->addRow("http://youtube.com/watch?v=", m_youtubeVideoIDWidget);
	layout->addRow(m_downloadProgressBar);
	layout->addRow(m_youtubeVideoButton);
	
	m_layout->addWidget(youtubeBox);
}

void SideBar::initLocalMusicWidgets() {
	QGroupBox *localMusicBox = new QGroupBox("Local file", this);
	QHBoxLayout *layout = new QHBoxLayout(localMusicBox);
	QPushButton *browseButton = new QPushButton("Browse music...", localMusicBox);
	
	layout->addWidget(browseButton);
	m_layout->addWidget(localMusicBox);
	
	connect(browseButton, &QPushButton::clicked, [&]() {
		QString localFilePath = QFileDialog::getOpenFileName(this, "Open File", "", "Audio files (*.mp3)");
		
		if (!localFilePath.isEmpty())
			m_mediaPlayer->playLocalFile(localFilePath, false);
	});
}

void SideBar::initSettingsWidgets() {
	QGroupBox *settingsBox = new QGroupBox("Settings", this);
	QVBoxLayout *layout = new QVBoxLayout(settingsBox);
	QCheckBox *kikooModeCheckBox = new QCheckBox("Kikoo mode", settingsBox);
	QCheckBox *freeMovementCheckBox = new QCheckBox("Free movement", settingsBox);
	
	layout->addWidget(kikooModeCheckBox);
	layout->addWidget(freeMovementCheckBox);
	m_layout->addWidget(settingsBox);
	
	connect(kikooModeCheckBox, SIGNAL(stateChanged(int)), m_glWidget->corewarRenderer(), SLOT(setKikooMode(int)));
	connect(m_glWidget, &GLWidget::kikooModeStateUpdated, [kikooModeCheckBox] (int state) {
		kikooModeCheckBox->setCheckState(Qt::CheckState(state));
	});
	connect(freeMovementCheckBox, &QCheckBox::stateChanged, [&] (int state) {
		m_glWidget->setFreeMovement(state == 2);
	});
}

void SideBar::initPlayerWidgets() {
	m_layout->addStretch();
	
	for (int i = 0 ; i < m_glWidget->app().program_amount ; i++) {
		m_playerWidgets.push_back(new PlayerWidget(i, this));
		m_layout->addWidget(m_playerWidgets[i]);
		connect(m_glWidget, SIGNAL(programUpdated(t_program &)), m_playerWidgets[i], SLOT(updateInfo(t_program &)));
	}
}

void SideBar::downloadProgress(qint64 read, qint64 total) {
	m_downloadProgressBar->setVisible(true);
	m_downloadProgressBar->setValue(read * 100 / total);
}

void SideBar::downloadYoutubeMusic() {
	m_mediaPlayer->playYoutubeURL(m_youtubeVideoIDWidget->text());
	
	m_youtubeVideoButton->setEnabled(false);
	m_youtubeVideoIDWidget->setEnabled(false);
}

void SideBar::downloadFinished() {
	m_youtubeVideoButton->setEnabled(true);
	m_youtubeVideoIDWidget->setEnabled(true);
	m_youtubeVideoIDWidget->setText("");
	m_downloadProgressBar->reset();
	m_downloadProgressBar->setVisible(false);
}

