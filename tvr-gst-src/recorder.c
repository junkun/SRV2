#include "recorder.h"


struct _recorder_data_private{

	GMainLoop *loop;
        GstElement *pipeline;
        GstBuffer *buff; /* Will be used with appsink instead of filesink */
        GstElement *source, *converter, *enc;
        GstElement *pitch, *pitch_convert;
        GstElement *sink;
	const gchar *filename;
};

/* Adding elements to pipeline 
 * and linking them 
 */

static void
tvr_add_elements_to_pipeline(recorder_data *rd){

	if(rd->priv->pitch){
		gst_bin_add_many(GST_BIN(rd->priv->pipeline), 
					rd->priv->source,
					rd->priv->converter,
					rd->priv->pitch,
					rd->priv->pitch_convert,
					rd->priv->enc,
					rd->priv->sink,
					NULL);

		gst_element_link_many(rd->priv->source,
					rd->priv->converter,
					rd->priv->pitch,
					rd->priv->pitch_convert,
					rd->priv->enc,
					rd->priv->sink,
					NULL);
						

	} else {

		gst_bin_add_many(GST_BIN(rd->priv->pipeline),
					rd->priv->source,
					rd->priv->converter,
					rd->priv->enc,
					rd->priv->sink,
					NULL);

		gst_element_link_many(rd->priv->source,
					rd->priv->converter,
					rd->priv->enc,
					rd->priv->sink,
					NULL);
	
	}


}

/* Checking if we have sound pitch property
 * and converting pitch with pitch_convert converter
 */

static void 
tvr_check_pitch_element_availability(GstElement *pitch, GstElement **pitch_convert){

	if(pitch){
		g_print("Pitch element available, creating pitch converter \n");
		*pitch_convert = gst_element_factory_make("audioconvert", NULL);	
	} else {
		g_warning("Pitch element unavailable \n");
	}

}

/* Inititalizes recorder and all 
 * relevant elements
 */ 

void tvr_init_recorder(recorder_data *rd, const gchar* filename){

	rd->priv = g_new0(recorder_data_private, 1);
	rd->priv->pipeline = gst_pipeline_new("TTS-Recorder");
	rd->priv->source = gst_element_factory_make("autoaudiosrc", NULL);
	rd->priv->converter = gst_element_factory_make("audioconvert", NULL);
	rd->priv->enc = gst_element_factory_make("wavenc", NULL);
	rd->priv->sink = gst_element_factory_make("filesink", NULL);
	rd->priv->pitch = gst_element_factory_make("pitchdetect", NULL);
	rd->priv->loop = g_main_loop_new(NULL, FALSE);
	rd->priv->filename = filename;
	g_object_set(rd->priv->sink, "location", filename, NULL);

	tvr_check_pitch_element_availability(rd->priv->pitch, &rd->priv->pitch_convert );

	tvr_add_elements_to_pipeline(rd);

}

/* @Starts Pipeline
 * voice recording starts
 * Should be used while keep
 * pressing the Push Button
 */

void tvr_pause_recorder_pipeline(recorder_data *rd){


	gst_element_set_state(rd->priv->pipeline, GST_STATE_PAUSED);
	g_main_loop_quit(rd->priv->loop);

}

void tvr_play_recorder_pipeline(recorder_data *rd){

	gst_element_set_state(rd->priv->pipeline, GST_STATE_PLAYING);
	g_main_loop_run(rd->priv->loop);

}

/* @Stop our pipeline! 
 * Should be used while Releasing 
 * Push Button.
 */

void tvr_stop_recorder_pipeline(recorder_data *rd){

	if(rd){
		if(rd->priv){
			gst_element_set_state(rd->priv->pipeline, GST_STATE_NULL);
			if(g_main_loop_is_running(rd->priv->loop)){
				g_debug("Stopping GMainLoop and unref \n");
				g_main_loop_quit(rd->priv->loop);
				g_main_loop_unref(rd->priv->loop);
			} else {
				g_main_loop_unref(rd->priv->loop);
			}
	
	/* Pipeline has all elements, so unrefing it results
	 * in unrefing the other elements which are in it 
	 */
			g_debug("pipeline cleaned up \n");
			g_object_unref(GST_OBJECT(rd->priv->pipeline));
			

			if(rd->priv){
				g_free(rd->priv);
				rd->priv = NULL;
			}
		}
	}
}
