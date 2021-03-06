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

class GLWidget;
class MediaPlayer;
class PlayerWidget;

class SideBar : public QWidget {
	Q_OBJECT
	
	public:
		SideBar(MediaPlayer *mediaPlayer, GLWidget *glWidget, QWidget *parent = nullptr);
		
		void initMusicPlayerWidgets();
		void initYoutubeWidgets();
		void initLocalMusicWidgets();
		void initSettingsWidgets();
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
		
		GLWidget *m_glWidget;
		MediaPlayer *m_mediaPlayer;
		
		std::vector<PlayerWidget *> m_playerWidgets;
};

#endif // SIDEBAR_HPP_
