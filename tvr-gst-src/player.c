#include "player.h"


struct _player_data_private{
	GstBus *bus;
        GMainLoop  *loop;
        GstElement *pipeline;
        GstBuffer  *buff; /* Will be used with appsink instead of filesink */
        GstElement *source;
	GstElement *converter;
        GstElement *parser;
        GstElement *sink;
	guint message;
	gint64 len;
	const gchar *filename;
};


static void
tvr_newly_created_pad_cb(GstElement *element,
				GstPad *new_pad,
				gpointer data){

	GstPad *conv_sink_pad;
	conv_sink_pad = gst_element_get_pad((GstElement *)data, "sink");
	gst_pad_link (new_pad, conv_sink_pad);

	gst_object_unref(conv_sink_pad);

}


/* Adding elements to pipeline 
 * and linking them 
 */

static void
tvr_add_elements_to_pipeline(player_data *pd){

						
	gst_bin_add_many(GST_BIN(pd->priv->pipeline),
				pd->priv->source,
				pd->priv->parser,
				pd->priv->converter,
				pd->priv->sink,
				NULL);

	gst_element_link(pd->priv->source,
				pd->priv->parser);

	gst_element_link(pd->priv->converter, 
				pd->priv->sink);

	g_signal_connect(pd->priv->parser, "pad-added", 
				G_CALLBACK(tvr_newly_created_pad_cb), 
				pd->priv->converter); 
	
}

/* Notifies us about any error or in the stream
 */ 

static gboolean
tvr_bus_callback(GstBus *bus, GstMessage *message, gpointer data){

	player_data *pd = (player_data *)data;

        switch(GST_MESSAGE_TYPE(message)){
                case GST_MESSAGE_EOS:
			pd->priv->message = GST_MESSAGE_TYPE(message);
			g_print("End of Stream reached: Quitting Main Loop \n");
			g_main_loop_quit(pd->priv->loop);
                        break;

	}

	return TRUE;
}

guint tvr_get_stream_length(player_data *pd){

	return pd->priv->len;

}

guint tvr_parse_stream_length(player_data *pd){

	GstFormat fmt = GST_FORMAT_TIME;

	if(gst_element_query_duration(pd->priv->pipeline, &fmt, &pd->priv->len)){
			pd->priv->len = GST_TIME_AS_SECONDS(pd->priv->len);
			g_print(" %d \n", pd->priv->len);
	}

	return 0;
}


/* Inititalizes player and all 
 * relevant elements
 */ 

void tvr_init_player(player_data *pd, const gchar *file){

	pd->priv = g_new0(player_data_private, 1); 	
	pd->priv->pipeline = gst_pipeline_new("TTS-Playback");
	pd->priv->source = gst_element_factory_make("filesrc", NULL);
	pd->priv->converter = gst_element_factory_make("audioconvert", NULL);
	pd->priv->parser = gst_element_factory_make("wavparse", NULL);
	pd->priv->sink = gst_element_factory_make("autoaudiosink", NULL);
	pd->priv->loop = g_main_loop_new(NULL, FALSE);
	pd->priv->filename = file;
	g_object_set(G_OBJECT(pd->priv->source), "location", pd->priv->filename, NULL);

	tvr_add_elements_to_pipeline(pd);

	/* Notification about errors in the stream or end of stream */

	pd->priv->bus = gst_pipeline_get_bus(GST_PIPELINE(pd->priv->pipeline));

	/* our callback */
	gst_bus_add_watch(pd->priv->bus, tvr_bus_callback, pd);
	gst_object_unref(pd->priv->bus);

}

/* @Starts Pipeline
 */

guint tvr_play_player_pipeline(player_data *pd){

	g_assert(pd != NULL);
	gst_element_set_state(pd->priv->pipeline, GST_STATE_PLAYING);
	g_main_loop_run(pd->priv->loop);
	return pd->priv->message;
}

/* Pauses pipeline 
 */

void tvr_pause_player_pipeline(player_data *pd){

	gst_element_set_state(pd->priv->pipeline, GST_STATE_PAUSED);
	g_main_loop_quit(pd->priv->loop);

}

/* @Stop our pipeline! 
 */

void tvr_stop_player_pipeline(player_data *pd){

	if(pd){
		if(pd->priv){
			gst_element_set_state(pd->priv->pipeline, GST_STATE_NULL);
			if(g_main_loop_is_running(pd->priv->loop)){
				g_debug("Stopping GMainLoop and unref \n");
				g_main_loop_quit(pd->priv->loop);
				g_debug("Unref Main Loop \n");
				g_main_loop_unref(pd->priv->loop);
			} else {
				g_main_loop_unref(pd->priv->loop);
			}
	
		/* Pipeline has all elements, so unrefing it results
		 * in unrefing the other elements which are in it 
		 */
			g_debug("pipeline cleaned up \n");
			gst_object_unref(pd->priv->pipeline);
		
			g_free(pd->priv);
			pd->priv = NULL;
		}
	}
}
