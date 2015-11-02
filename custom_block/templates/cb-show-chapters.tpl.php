<?php //dpm($content); ?>
<?php drupal_add_css(drupal_get_path('module', 'media_cc_chapters') . '/css/media_cc_chapters.css'); ?>
<?php drupal_add_js(drupal_get_path('module', 'media_cc_chapters') . '/js/media_cc_chapters.js'); ?>
<?php if (!empty($content)): ?>
  <ol class='video-chapters'>
    <?php foreach($content as $chapter): ?>
      <li id="<?php print $chapter->video_chapters_cid;?>" class="chapter-trigger" data-cid="<?php print $chapter->video_chapters_cid;?>" data-fid="<?php print $chapter->entity_id;?>">
        <span class="chapter-title">
          <?php print $chapter->video_chapters_title;?>
        </span> - 
        <span class="chapter-start">
           <?php if (isset($chapter->video_chapters_start)): ?>
             <?php print gmdate('H:i:s', $chapter->video_chapters_start); ?>
          <?php endif; ?>
        </span>
      </li>
    <?php endforeach; ?>
  </ol>
<?php endif; ?>

<?php //$contact_form = module_invoke('custom_contact', 'block_view', 'show_chapters_block'); ?>
<?php //print render($contact_form['content']); ?>

<?php $chapters_block = module_invoke('views', 'block_view', 'show_chapters-block'); ?>
<?php print render($chapters_block['content']); ?>
