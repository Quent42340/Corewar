/*
 * =====================================================================================
 *
 *       Filename:  SideBar.hpp
 *
 *    Description:  
 *
 *        Created:  27/03/2016 15:21:35
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SIDEBAR_HPP_
#define SIDEBAR_HPP_

#include <QLabel>
#include <QLineEdit>
#include <QProgressBar>
#include <QPushButton>
#include <QVBoxLayout>

class MediaPlayer;
class PlayerWidget;

class SideBar : public QWidget {
	Q_OBJECT
	
	public:
		SideBar(MediaPlayer *mediaPlayer, QWidget *parent = nullptr);
		
		void initYoutubeWidgets();
		void initPlayerWidgets();
		
	public slots:
		void downloadProgress(qint64 read, qint64 total);
		void downloadYoutubeMusic();
		void downloadFinished();
		
	private:
		QVBoxLayout *m_layout;
		QLineEdit *m_youtubeVideoIDWidget;
		QPushButton *m_youtubeVideoButton;
		QProgressBar *m_downloadProgressBar;
		
		MediaPlayer *m_mediaPlayer;
		
		PlayerWidget *m_playerWidgets[4];
};

#endif // SIDEBAR_HPP_
