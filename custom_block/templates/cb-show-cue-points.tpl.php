<!--<?php if (!empty($content)): ?>
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
<?php endif; ?>-->
<ul class="video-chapters-cue-points">
  <?php foreach($content as $cue_point): ?>
    <li>
      <div class="cue-field-popcornjs">
        <a href="#" data-cfpopcorn-id="<?php print $cue_point['fid']; ?>" data-cfpopcorn-start="<?php print $cue_point['start']; ?>" data-cfpopcorn-title="4. Planning Day" data-cfpopcorn-type="cue_field_popcornjs">
          <span class="title"><?php print $cue_point['title']; ?></span> — 
          <span class="hms hms-format-m-ss"><?php print gmdate('H:i:s', $cue_point['start']); ?></span>
        </a>
      </div>
    </li>
  <?php endforeach; ?>
</ul>


<?php //$chapters_block = module_invoke('views', 'block_view', 'show_chapters-block'); ?>
<?php //print render($chapters_block['content']); ?>