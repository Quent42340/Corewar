/*
 * =====================================================================================
 *
 *       Filename:  MediaPlayer.cpp
 *
 *    Description:  
 *
 *        Created:  27/03/2016 14:23:06
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <QCoreApplication>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QNetworkReply>
#include <QTimer>
#include <QWebElementCollection>
#include <QWebFrame>

#include "MediaPlayer.hpp"

MediaPlayer::MediaPlayer(QWidget *parent) : QWidget(parent) {
	m_audioProbe.setSource(&m_player);
	
	connect(m_page.mainFrame(), SIGNAL(loadFinished(bool)), this, SLOT(loadFinished(bool)));
}

void MediaPlayer::playLocalFile(const QString &localFilePath, bool relativePath) {
	QString path;
	if (relativePath)
		path = QCoreApplication::applicationDirPath() + "/";
	
	m_player.setMedia(QUrl::fromLocalFile(path + localFilePath));
	m_player.play();
	
	m_currentMusic = localFilePath;
	emit musicChanged(localFilePath);
}

void MediaPlayer::playYoutubeURL(const QString &videoID) {
	m_currentYoutubeID = videoID;
	
	m_page.mainFrame()->load(QUrl("http://api.convert2mp3.cc/?v=" + videoID));
}

void MediaPlayer::downloadYoutubeFile() {
	if (m_page.mainFrame()->findFirstElement(".buttonStartConversion").toPlainText() == "Convert") {
		QMessageBox::critical(nullptr, "Error", "Invalid video ID");
		emit downloadFinished();
		return;
	}
	
	if (m_page.mainFrame()->findFirstElement(".videohref").attribute("href") == "") {
		QTimer::singleShot(0.5_sec, this, SLOT(downloadYoutubeFile()));
		return;
	}
	
	QNetworkRequest request;
	request.setUrl(QUrl("https://www.googleapis.com/youtube/v3/videos?part=snippet&id=" + m_currentYoutubeID + "&fields=items(snippet(title))&key=AIzaSyBRoz7RlLHatCYhPAEUJIMGNd0taTDh1io"));
	
	m_nameReply = m_networkManager.get(request);
	connect(m_nameReply, SIGNAL(finished()), this, SLOT(getNextVideoName()));
	
	request.setUrl(m_page.mainFrame()->findFirstElement(".videohref").attribute("href"));
	
	m_contentReply = m_networkManager.get(request);
	connect(m_contentReply, SIGNAL(finished()), this, SLOT(saveAndPlay()));
	connect(m_contentReply, SIGNAL(downloadProgress(qint64, qint64)), this, SIGNAL(downloadProgress(qint64, qint64)));
}

void MediaPlayer::getNextVideoName() {
	QJsonObject youtubeInfo(QJsonDocument::fromJson(QString(m_nameReply->readAll()).toUtf8()).object());
	
	m_nextMusic = youtubeInfo.value("items").toArray()[0].toObject().value("snippet").toObject().value("title").toString();
}

void MediaPlayer::loadFinished(bool ok) {
	if (ok) {
		m_page.mainFrame()->evaluateJavaScript("document.getElementsByClassName('buttonStartConversion')[0].click()");
		
		downloadYoutubeFile();
	} else {
		m_currentMusic = "";
		
		// qCritical() << "Error: Failed to load webpage";
	}
}

void MediaPlayer::saveAndPlay() {
	QFile file("/tmp/song.mp3");
	if (!file.open(QIODevice::WriteOnly))
		qCritical() << "Error: Unable to open /tmp/song.mp3";
	file.write(m_contentReply->readAll());
	file.close();
	
	m_player.setMedia(QUrl::fromLocalFile("/tmp/song.mp3"));
	m_player.setVolume(60);
	m_player.play();
	
	m_currentMusic = m_nextMusic;
	emit musicChanged(m_currentMusic);
	emit downloadFinished();
}

