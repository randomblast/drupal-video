<?php

/**
 * Page for admin/config/media/video-styles
 */
function video_styles_page()
{
//  $res = db_query("SELECT name FROM {video_styles};");

  return t(
    "Video styles are made up of arguments to ffmpeg, which will be applied to any uploaded videos and can be "
  . "selected for inclusion as source arguments for generated HTML5 &lt;video&gt; elements. They will also be available "
  . "to views as content sources"
  );
}

function video_add_style_form()
{
  $form['name'] = array
  (
    '#type' => 'textfield'
  , '#title' => 'Name'
  , '#description' => 'Use only letters, numbers,-, and _ characters'
  );

  $form['maintain_aspect_ratio'] = array
  (
    '#type' => 'checkbox'
  , '#title' => 'Maintain aspect ratio'
  );

  return $form;
}
