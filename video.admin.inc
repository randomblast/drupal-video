<?php

/**
 * Page for admin/config/media/video-styles
 */
function video_styles_page()
{
  ob_start();
//  $res = db_query("SELECT name FROM {video_styles};");

  echo '<p>'.t(
    "Video styles are made up of arguments to ffmpeg, which will be applied to any uploaded videos and can be "
  . "selected for inclusion as source arguments for generated HTML5 &lt;video&gt; elements. They will also be available "
  . "to views as content sources"
  ).'</p>';

  echo l('Add Style', 'admin/config/media/video-styles/add');

  return ob_get_clean();
}

function video_add_style_form()
{
  $form['name'] = array
  (
    '#type' => 'textfield'
  , '#title' => 'Name'
  , '#description' => 'Use only letters, numbers,-, and _ characters'
  );

  $form['container'] = array
  (
    '#type' => 'select'
  , '#title' => 'Container Format'
  , '#options' => video_available_container_formats()
  );

  $form['dimensions'] = array
  (
    '#type' => 'fieldset'
  , '#title' => 'Dimensions'
  );

  $form['dimensions']['maintain_aspect_ratio'] = array
  (
    '#type' => 'checkbox'
  , '#title' => 'Maintain aspect ratio'
  , '#default_value' => TRUE
  );

  $form['dimensions']['max_width'] = array
  (
    '#type' => 'textfield'
  , '#title' => 'Maximum width'
  , '#size' => 5
  );

  $form['dimensions']['max_height'] = array
  (
    '#type' => 'textfield'
  , '#title' => 'Maximum height'
  , '#size' => 5
  );

  $form['video'] = array
  (
    '#type' => 'fieldset'
  , '#title' => 'Video settings'
  );

  $form['video']['codec'] = array
  (
    '#type' => 'select'
  , '#options' => video_available_video_codecs()
  );

  $form['video']['bitrate'] = array
  (
    '#type' => 'textfield'
  , '#title' => 'Bitrate'
  , '#size' => 5
  , '#field_suffix' => 'kbps'
  );

  return $form;
}
