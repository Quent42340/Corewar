/*
 * =====================================================================================
 *
 *       Filename:  MediaPlayer.hpp
 *
 *    Description:  
 *
 *        Created:  27/03/2016 14:22:37
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MEDIAPLAYER_HPP_
#define MEDIAPLAYER_HPP_

#include <QAudioProbe>
#include <QMediaPlayer>
#include <QNetworkAccessManager>
#include <QWebPage>

// Converts to milliseconds
constexpr unsigned int operator""_sec(long double n) { return n * 1000; }
constexpr unsigned int operator""_min(long double n) { return n * 60.0_sec; }
constexpr unsigned int operator""_h(long double n)   { return n * 60.0_min; }

class MediaPlayer : public QObject {
	Q_OBJECT
	
	public:
		MediaPlayer();
		
		const QAudioProbe &audioProbe() const { return m_audioProbe; }
		const QString &currentMusic() const { return m_currentMusic; }
		
	signals:
		void downloadProgress(qint64 read, qint64 total);
		void downloadFinished();
		
	public slots:
		void playYoutubeURL(const QString &videoID);
		void downloadYoutubeFile();
		
		void loadFinished(bool ok);
		void saveAndPlay(QNetworkReply *reply);
		
	private:
		QMediaPlayer m_player{this, QMediaPlayer::StreamPlayback};
		QAudioProbe m_audioProbe;
		
		QNetworkAccessManager m_networkManager;
		QWebPage m_page;
		
		QString m_currentMusic;
		QString m_nextMusic;
};

#endif // MEDIAPLAYER_HPP_
