#ifndef RECORDER_H
#define RECORDER_H

#include <gst/gst.h>

G_BEGIN_DECLS

typedef struct _recorder_data recorder_data;
typedef struct _recorder_data_private recorder_data_private;

struct	_recorder_data{
	recorder_data_private *priv;
};


/* initializes voice recording */
void tvr_init_recorder(recorder_data *, const gchar *);

/* Starts recording voice */
void tvr_play_recorder_pipeline(recorder_data *);

/* Stop recording voice and freeing resources*/
void tvr_stop_recorder_pipeline(recorder_data *);

/* Pauses pipeline */
void tvr_pause_recorder_pipeline(recorder_data *);

G_END_DECLS


#endif
