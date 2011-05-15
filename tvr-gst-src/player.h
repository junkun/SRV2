#ifndef PLAYER_H
#define PLAYER_H

//#include <gst/gst.h>
#include <gstreamer-0.10/gst/gst.h>


G_BEGIN_DECLS

typedef struct _player_data player_data;
typedef struct _player_data_private player_data_private;

struct	_player_data{
	player_data_private *priv;
};


/* initializes voice recording */
void tvr_init_player(player_data *, const gchar *);

/* Starts recording voice */
guint tvr_play_player_pipeline(player_data *);

/* Stop recording voice and freeing resources*/
void tvr_stop_player_pipeline(player_data *);

/* Pause pipeline */
void tvr_pause_player_pipeline(player_data *);

/* Parse media length */
guint tvr_parse_stream_length(player_data *);

/* Get Stream length */
guint tvr_get_stream_length(player_data *);

G_END_DECLS

#endif
