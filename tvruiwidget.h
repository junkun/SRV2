#ifndef TVRUIWIDGET_H
#define TVRUIWIDGET_H

#include <QWidget>
#include <QTimer>

#include "ui_tvr.h"
#include "tvr-gst-src/recorder.h"
#include "tvr-gst-src/player.h"


class TvrUiWidget : public QMainWindow, public Ui::tvrWindow {

    Q_OBJECT
public:
    explicit TvrUiWidget(QMainWindow *parent = 0);

        private:
                void setMainDialog();
                void setButtonStatus(bool, bool, bool, bool, bool, bool);
                void setProgressDialog();
        private:
                void showSaveFileDlg();
                bool showOpenFileDlg();
                void showSaveMessageDlg();
        private:
                void stopMedia();
                void playMedia();
                bool saveMedia();
                bool saveAsMedia();
                void updateBar();
                void checkFileAndSave();
        private:
                QString getFileName(QString);
                bool isLRAvailable() const;
                bool getFileOpenedState() const;
                bool getRecordingState() const;
                bool getRecordingPausedState() const;
                bool getPlayingState() const;
                bool getPlayingPausedState() const;
                bool getStoppedState() const;
                bool getFileSavedState() const;
                bool getFileSavedAsState() const;
        private:
                void setLastRecording(bool);
                void setFileOpenedState(bool);
                void setRecordingState(bool);
                void setRecordingPausedState(bool);
                void setPlayingState(bool);
                void setPlayingPausedState(bool);
                void setStoppedState(bool);
                void setFileSaveState(bool);
                void setFileSaveAsState(bool);

        private slots:
                void on_actionVolume_triggered();
                void on_actionNew_triggered();
                void on_actionSave_triggered();
                void on_actionSaveAs_triggered();
                void on_actionAbout_triggered();
                void on_actionOpen_triggered();
                void on_actionExit_triggered();
                void on_actionRecord_triggered();
                void on_actionStop_triggered();
                void on_actionPlay_triggered();
                void on_actionPaused_triggered();

                void updateProgressBar();
        private:
                recorder_data *rd;
                player_data *pd;

                QString tFile;
                QString fileName;
                QString fileNameO;
                QString lastFile;
                QString str;

                QTimer *t;

                int	seconds; /* seconds to hold */
                int	secondsCopy; /* seconds copy */
                int	retValue;
                int 	count;
                int	progBarValue; /* Progress Bar Value */
                bool    lastRecording; /* Flag for last recording */
                bool	fileOpened; /* Open File flag */
                bool	fileSaved; /* Save File flag */
                bool	fileSavedAs; /* Save as File flag */
                bool	recording; /* Recording flag */
                bool	playing; /* Playing Flag */
                bool    recordingPaused; /* Recording Paused Flag  yeeey !!*/
                bool	playingPaused; /* Playing Paused Flag */
                bool	stopped; /* Stopped Flag  Duuuuuh =_=*/
                bool	playButtonClicked;

public slots:

};

#endif // TVRUIWIDGET_H
