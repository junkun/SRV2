#include <QtGui>
#include <QFileDialog>
#include <QMessageBox>
#include <QFileInfo>
#include <QDebug>
#include "tvruiwidget.h"


TvrUiWidget::TvrUiWidget(QMainWindow *parent) : QMainWindow(parent){

  setupUi(this) ;
    setMainDialog();
    setProgressDialog();

    rd = NULL;
    pd = NULL;

    tFile = "/tmp/recording4aq.wav";

    seconds = 0;
    retValue = 100;
    progBarValue = 0;
    count = 0;

    lastRecording = false;
    fileOpened = false;
    fileSaved = false;
    recording = false;
    recordingPaused = false;
    playing = false;
    playingPaused = false;
    stopped = false;
    playButtonClicked = false;

}
void TvrUiWidget::setProgressDialog(){
        t = new QTimer();
        QObject::connect(t, SIGNAL(timeout()), this, SLOT(updateProgressBar()));

}

QString TvrUiWidget::getFileName(QString file) {

        QFileInfo fInfo(file);
        return fInfo.completeBaseName() + "." + fInfo.completeSuffix();
}


bool TvrUiWidget::getRecordingState() const {

        return recording;

}

bool TvrUiWidget::getRecordingPausedState() const {

        return recordingPaused;
}


bool TvrUiWidget::getPlayingState() const {

        return playing;

}

bool TvrUiWidget::getPlayingPausedState() const {

        return playingPaused;

}

bool TvrUiWidget::getStoppedState() const {

        return stopped;

}

bool TvrUiWidget::getFileSavedState() const {

        return fileSaved;

}

bool TvrUiWidget::getFileOpenedState() const {

        return fileOpened;

}

void TvrUiWidget::setFileOpenedState(bool fileOState){

        fileOpened = fileOState;

}


void TvrUiWidget::setRecordingState(bool recState){

        recording = recState;

}

void TvrUiWidget::setRecordingPausedState(bool recPausedstate){

        recordingPaused = recPausedstate;

}

void TvrUiWidget::setPlayingState(bool playingState){

        playing = playingState;

}

void TvrUiWidget::setPlayingPausedState(bool playingPausedState){

        playingPaused = playingPausedState;

}

void TvrUiWidget::setStoppedState(bool stoppedState){

        stopped = stoppedState;

}

void TvrUiWidget::setFileSaveState(bool fileSaveState){

        fileSaved = fileSaveState;

}

void TvrUiWidget::setFileSaveAsState(bool fileSaveAsState){

        fileSavedAs = fileSaveAsState;

}

bool TvrUiWidget::isLRAvailable() const{

    return lastRecording;

}


void TvrUiWidget::setButtonStatus(bool record, bool play, bool pause,
                                        bool stop, bool save, bool saveAs){

        actionRecord->setEnabled(record);
        actionPlay->setEnabled(play);
        actionPaused->setEnabled(pause);
        actionStop->setEnabled(stop);
        actionSave->setEnabled(save);
        actionSaveAs->setEnabled(saveAs);


}

void TvrUiWidget::setMainDialog(){

        actionPlay->setEnabled(false);
        actionStop->setEnabled(false);
        actionPaused->setEnabled(false);
        actionSave->setEnabled(false);
        actionSaveAs->setEnabled(false);
}

void TvrUiWidget::updateBar(){

        if (count == 0){
                retValue = retValue / seconds;
                count++;
        }


        if (seconds >= 0){
                lengthFieldEditLabel->setText(QString::number(seconds, 10));
                progBarValue = progBarValue + retValue;
                tvrProgressBar->setValue(progBarValue);
                seconds--;
        }


}


void TvrUiWidget::updateProgressBar(){

        if(getFileOpenedState() || getPlayingState()){

                if(playButtonClicked){
                        updateBar();
                        return;
                }

                if(seconds == 0) {
                        if( tvr_get_stream_length(pd) == 0){
                                return;
                        } else {
                                secondsCopy = tvr_get_stream_length(pd);
                                seconds = secondsCopy;
                        }
                }

                updateBar();
                return;

        }

        if(getRecordingState()) {
                    lengthFieldEditLabel->setText(QString::number(seconds, 10));
                    secondsCopy = seconds;
                    seconds++;
                    return;
        }

}


void TvrUiWidget::showSaveMessageDlg(){

        if(getFileSavedState()){
                QMessageBox::information(this, "Guardado",
                                                "Archivo guardado exitosamente",
                                                 QMessageBox::Ok);
        }
        if(!getFileSavedState() && !fileName.isEmpty()) {
                QMessageBox::critical(this, "Error",
                                            "Archivo no puede ser salvado : Cheka si tienes\n"
                                            " permisos sobre este directorio",
                                            QMessageBox::Ok);
        }

}

void TvrUiWidget::showSaveFileDlg(){

        int ret = QMessageBox::question (this, "Guardar Grabación",
                                                "Desea guardar ultima grabación",
                                                 QMessageBox::Save | QMessageBox::Discard,
                                                 QMessageBox::Save);

        if (ret == QMessageBox::Save){
                saveMedia();
                showSaveMessageDlg();
        } else {
                setButtonStatus(true, false, false, false, true, true);
        }


        setStoppedState(false);

}


bool TvrUiWidget::showOpenFileDlg(){

        fileNameO = QFileDialog::getOpenFileName(this, tr("Abrir archivo"),
                                                        "/home/jonathan/Qt_projects/srv/srv/db/corpus",
                                                        tr("Audio (*.wav *.mp3)"));

        if(fileNameO.isEmpty()){
                return getFileOpenedState();
        } else {
                fileNameEditLabel->setText(getFileName(fileNameO));
                setFileOpenedState(true);
        }

return true;
}

bool TvrUiWidget::saveAsMedia(){
    /*saveAsMedia is just cp the temp file tFile in the new location */
        fileName = QFileDialog::getSaveFileName(this,
                                                "Guardar como",
                                                "/home/jonathan/Qt_projects/srv/srv/db/corpus",
                                                "Archivos de sonido (*.wav)");

        fileNameEditLabel->setText(getFileName(fileName));

        if(fileName.isEmpty()){
                setFileSaveAsState(false);
                return false;
        } else {
                QString cpyAct = "cp ";
                cpyAct.append(lastFile);
                cpyAct.append(" ");
                cpyAct.append(fileName);
                if(system(cpyAct.toStdString().c_str()) > 0){
                        setFileSaveAsState(false);
                        return false;
                }
                setFileSaveAsState(true);
        }
return true;

}

bool TvrUiWidget::saveMedia(){


        fileName = QFileDialog::getSaveFileName(this,
                                                "Guardar Grabación a",
                                                "/home/jonathan/Qt_projects/srv/srv/db/corpus",
                                                "Sound Files (*.wav)");

        fileNameEditLabel->setText(getFileName(fileName));

        if(fileName.isEmpty()){
                setFileSaveState(false);
                return false;
        } else {
                lastFile = fileName;
                QString cpyAct = "cp ";
                cpyAct.append(tFile);
                cpyAct.append(" ");
                cpyAct.append(fileName);
                if(system(cpyAct.toStdString().c_str()) > 0){
                        setFileSaveState(false);
                        return false;
                }
                setFileSaveState(true);
        }
return true;
}

void TvrUiWidget::playMedia(){


        statusLabelEdit->setText("Reproduciendo ...");

        setPlayingPausedState(false);
        setPlayingState(true);

        setButtonStatus(false, false, true, true, true, true);

        if(tvr_play_player_pipeline(pd) == GST_MESSAGE_EOS){
                stopMedia();
        }

}

void TvrUiWidget::setLastRecording(bool lastRecordingState){

    lastRecording = lastRecordingState;
}


void TvrUiWidget::stopMedia(){


    if(getRecordingState() || getRecordingPausedState()){
        tvr_stop_recorder_pipeline(rd);
        if(rd){
            g_free(rd);
            rd = NULL;
        }
        setRecordingState(false);
        setRecordingPausedState(false);
        setLastRecording(true);
    }

    if(getPlayingState() || getPlayingPausedState()){
        tvr_stop_player_pipeline(pd);
        if(pd){
            g_free(pd);
            pd = NULL;
        }

        if(playButtonClicked){
            playButtonClicked = false;
        }
        setPlayingState(false);
        setPlayingPausedState(false);
    }
        // Stop Timer
        t->stop();

        // Values need to be reset
        progBarValue = 0;
        retValue = 100;
        count = 0;
        seconds = 0;

        // Progress Bar needs to be reset
        tvrProgressBar->setValue(0);
        lengthFieldEditLabel->setText("0");

        // Close all states
        setFileOpenedState(false);
        setFileSaveState(false);

        // Set Buttons Status
        setButtonStatus(true, true, false, false, true, true);

        statusLabelEdit->setText("Detenido");


}




void TvrUiWidget::on_actionNew_triggered(){

        if(getRecordingState() || getRecordingPausedState()
            || getPlayingState() || getPlayingPausedState()){
            stopMedia();
        }

        if(!getFileSavedState()){
                if(isLRAvailable()){
                    showSaveFileDlg();
                }
        }
        setLastRecording(false);

        if(getFileSavedState()){
                setButtonStatus(true, false, false, false, false, true);
        }
}

void TvrUiWidget::on_actionOpen_triggered(){

    if(getRecordingState() || getRecordingPausedState()
        || getPlayingState() || getPlayingPausedState()){
        stopMedia();
    }

    if(!getFileSavedState()){
            if(isLRAvailable()){
                showSaveFileDlg();
            }
    }

    setLastRecording(false);

    if(showOpenFileDlg()){
        pd = g_new0(player_data, 1);
        tvr_init_player(pd, fileNameO.toStdString().c_str());
        g_timeout_add(1000, (GSourceFunc)tvr_parse_stream_length, pd);
        setFileOpenedState(true);
        t->start(1000);
        playMedia();
    }

}

void TvrUiWidget::on_actionVolume_triggered(){

        /*Open gnome-volume-control app */
        gchar *vol_control_path;
        GError *error = NULL;
        gint vol_control_path_idx = 0;
        bool result;

        vol_control_path = g_find_program_in_path("gnome-volume-control");

        if(vol_control_path == NULL){
                QMessageBox::critical(this, "Error abrirndo control de volumen",
                                                "gnome-volume-control no esta instalado\n"
                                                "en el path.",
                                                QMessageBox::Close);
        }

        gchar *vol_control_with_switch[] = {NULL, "--page", "--recording", NULL};

        vol_control_with_switch[vol_control_path_idx] = vol_control_path;

        result = g_spawn_async (NULL,
                                vol_control_with_switch,
                                NULL,
                                G_SPAWN_LEAVE_DESCRIPTORS_OPEN,
                                NULL,
                                NULL,
                                NULL,
                                &error);

        if(!result){
                QString errorMsg = error->message;

                QMessageBox::critical(this, "Error inicializando Control de Volumen",
                                                "Un error ocurrió mientras iniciaba \n"
                                                "gnome-volume-control " + errorMsg,
                                                QMessageBox::Close);
                g_error_free(error);

        }

        g_free(vol_control_path);
}

void TvrUiWidget::on_actionSave_triggered(){

    if(getRecordingState() || getRecordingPausedState()
        || getPlayingState() || getPlayingPausedState()){
        stopMedia();
    }

    if(isLRAvailable()){
        showSaveFileDlg();
    }
        showSaveMessageDlg();
        setStoppedState(false);
        setButtonStatus(true, false, false, false, false, true);
}

void TvrUiWidget::checkFileAndSave(){

        if(isLRAvailable()){ // If we have last recording available
                saveMedia();
        } else {
                if(saveAsMedia()){
                        showSaveMessageDlg();
                }
        }
}

void TvrUiWidget::on_actionSaveAs_triggered(){

    if(getRecordingState() || getRecordingPausedState()
        || getPlayingState() || getPlayingPausedState()){
        stopMedia();
    }
    if(isLRAvailable()){
        checkFileAndSave();
    }
        showSaveMessageDlg();
        setStoppedState(false);
        setButtonStatus(true, false, false, false, false, true);
}

void TvrUiWidget::on_actionExit_triggered(){

        stopMedia();
        QApplication::quit();

}

void TvrUiWidget::on_actionAbout_triggered(){


        QMessageBox::information(this, "SRV",
                                 "Sitema de Reconocimiento de Voz \n\n Author: TT-2010-0036\n\n"
                                 "First Beta Release \n 0.1 \n",
                                QMessageBox::Ok);

}

void TvrUiWidget::on_actionRecord_triggered(){

        if(!getRecordingState() && !getRecordingPausedState()){
                if(!getFileSavedState()){
                        if(isLRAvailable()) {
                                showSaveFileDlg();
                        }
                }
                setButtonStatus(false, false, true, true, true, true);
                rd = g_new0(recorder_data, 1);
                tvr_init_recorder(rd, tFile.toStdString().c_str());
                seconds = 0;
        }
        statusLabelEdit->setText("Grabando ...");
        setRecordingState(true);
        setFileOpenedState(false);
        setButtonStatus(false, false, true, true, true, true);
        t->start(1000);
        tvr_play_recorder_pipeline(rd);
}


void TvrUiWidget::on_actionStop_triggered(){
        t->stop();
        stopMedia();
}


void TvrUiWidget::on_actionPlay_triggered(){

        if(!getPlayingState() && !getPlayingPausedState()){
                pd = g_new0(player_data, 1);
                statusLabelEdit->setText("Reproduciendo ...");
                if(isLRAvailable()) {
                        tvr_init_player(pd, tFile.toStdString().c_str());
                } else {
                        tvr_init_player(pd, fileNameO.toStdString().c_str());
                }
        }

        if(!getPlayingPausedState()){
                seconds = secondsCopy;
        }

        playButtonClicked = true;
        t->start(1000);
        playMedia();

}

void TvrUiWidget::on_actionPaused_triggered(){

        if(getRecordingState()){
                setRecordingState(false);
                setRecordingPausedState(true);
                statusLabelEdit->setText("Grabando : Pausado");
                setButtonStatus(true, false, false, true, true, true);
                tvr_pause_recorder_pipeline(rd);
        }

        if(getPlayingState()){
                setPlayingState(false);
                setPlayingPausedState(true);
                statusLabelEdit->setText("Reproduciendo : Pausado");
                setButtonStatus(false, true, false, true, true, true);
                tvr_pause_player_pipeline(pd);
        }

}
