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
#include <QNetworkReply>
#include <QTimer>
#include <QWebElementCollection>
#include <QWebFrame>

#include "MediaPlayer.hpp"

MediaPlayer::MediaPlayer() {
	m_audioProbe.setSource(&m_player);
	// player.setMedia(QUrl::fromLocalFile(QCoreApplication::applicationDirPath() + "/resources/audio/hello.mp3"));
	m_player.setMedia(QUrl::fromLocalFile(QCoreApplication::applicationDirPath() + "/resources/audio/song_of_storms.mp3"));
	m_player.play();
	
	m_currentMusic = m_player.media().canonicalUrl().toString();
	
	connect(m_page.mainFrame(), SIGNAL(loadFinished(bool)), this, SLOT(loadFinished(bool)));
	connect(&m_networkManager, SIGNAL(finished(QNetworkReply *)), this, SLOT(saveAndPlay(QNetworkReply *)));
}

void MediaPlayer::playYoutubeURL(const QString &videoID) {
	m_page.mainFrame()->load(QUrl("http://api.convert2mp3.cc/?v=" + videoID));
}

void MediaPlayer::downloadYoutubeFile() {
	if (m_page.mainFrame()->findFirstElement(".videohref").attribute("href") == "") {
		QTimer::singleShot(0.5_sec, this, SLOT(downloadYoutubeFile()));
		return;
	}
	
	// m_nextMusic = m_page.mainFrame()->
	
	QNetworkRequest request;
	request.setUrl(m_page.mainFrame()->findFirstElement(".videohref").attribute("href"));
	
	QNetworkReply *reply = m_networkManager.get(request);
	connect(reply, SIGNAL(downloadProgress(qint64, qint64)), this, SIGNAL(downloadProgress(qint64, qint64)));
}

void MediaPlayer::loadFinished(bool ok) {
	if (ok) {
		m_currentMusic = m_nextMusic;
		
		m_page.mainFrame()->evaluateJavaScript("document.getElementsByClassName('buttonStartConversion')[0].click()");
		
		downloadYoutubeFile();
	} else {
		m_currentMusic = "";
		
		qCritical() << "Error: Failed to load webpage";
	}
}

void MediaPlayer::saveAndPlay(QNetworkReply *reply) {
	QFile file("/tmp/song.mp3");
	if (!file.open(QIODevice::WriteOnly))
		qCritical() << "Error: Unable to open /tmp/song.mp3";
	file.write(reply->readAll());
	file.close();
	
	m_player.setMedia(QUrl::fromLocalFile("/tmp/song.mp3"));
	m_player.setVolume(60);
	m_player.play();
	
	emit downloadFinished();
}

