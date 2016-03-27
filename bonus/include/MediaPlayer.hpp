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

class MediaPlayer : public QWidget {
	Q_OBJECT
	
	public:
		MediaPlayer();
		
		const QAudioProbe &audioProbe() const { return m_audioProbe; }
		
	signals:
		void downloadProgress(qint64 read, qint64 total);
		void downloadFinished();
		void musicChanged(const QString &name);
		
	public slots:
		void playYoutubeURL(const QString &videoID);
		void downloadYoutubeFile();
		
		void getNextVideoName();
		void loadFinished(bool ok);
		void saveAndPlay();
		
	private:
		QMediaPlayer m_player{this, QMediaPlayer::StreamPlayback};
		QAudioProbe m_audioProbe;
		
		QNetworkAccessManager m_networkManager;
		QWebPage m_page;
		
		QNetworkReply *m_nameReply;
		QNetworkReply *m_contentReply;
		
		QString m_currentYoutubeID;
		QString m_currentMusic;
		QString m_nextMusic;
};

#endif // MEDIAPLAYER_HPP_
