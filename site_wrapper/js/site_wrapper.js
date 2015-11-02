(function($) {

  
  Drupal.behaviors.headerDropDown = {
    attach: function(context, settings) {
      //$(document).ready(function() {
        $('nav#site-wrapper-main-menu li ul').hide();
        $('nav#site-wrapper-main-menu ul.first-level li').hover(
          function () {
            $('ul.second-level', this).show();
          },
          function () {
            $('ul.second-level', this).hide();
          }
        );
        $('ul.third-level').hide();
        $('nav#site-wrapper-main-menu ul.second-level li').hover(
          function () {
            $('ul.third-level', this).show();
          },
          function () {
            $('ul.third-level', this).hide();
          }
        );        
      //});
      
      var windowWidth = $(window).width();
      if (windowWidth <= 768) {
        $('nav#site-wrapper-main-menu ul.first-level li.item-1 a').first().toggle(function(e) {
          //console.log('wtf');
          e.preventDefault();
          //$('ul.second-level', this).show();
          $(this).parent().find('ul.second-level').show();
        }, function () {
          //console.log( $(this).parent().find('ul.second-level') );
          $(this).parent().find('ul.second-level').hide();
          //$(this).parent().next().hide();
          //$('ul.second-level', this).hide();
        });
        
        $('nav#site-wrapper-main-menu ul.first-level li.item-2 a').first().toggle(function(e) {
          //console.log('wtf');
          e.preventDefault();
          $(this).parent().find('ul.second-level').show();
          //$('ul.second-level', this).show();
        }, function () {
          //$(this).find('ul.second-level').hide();
          $(this).parent().find('ul.second-level').hide();
          //$('ul.second-level', this).hide();
        });
      }
    }
  };    
})(jQuery);
