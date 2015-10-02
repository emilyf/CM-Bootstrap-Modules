(function($) {
  Drupal.behaviors.front_pg_slider_initialize_flexslider = {
    attach: function (context, settings) {
      $(window).load(function() {
        $('.flexslider').flexslider({
          animation: "slide",
          controlNav: false,
          slideshow: false,
        });
      });
    }
  };   
})(jQuery);