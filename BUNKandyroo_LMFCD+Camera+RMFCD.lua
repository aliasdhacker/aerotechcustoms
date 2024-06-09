_  = function(p) return p; end;
name = _('Camera + RMPD (APACHE)');
Description = 'Right MPD on a separate screen with a 600x800 resolution.'
Viewports =
{
     Center =
     {
          x = 0;
          y = 0;
          width  = screen.width - 600;
          height = screen.height;
          viewDx = 0;
          viewDy = 0;
          aspect = screen.aspect;
     }
}

RIGHT_MFCD =
{
     x = screen.width - 600;
     y = 50; -- moves the top down
     width = 600;
     height = 700; -- this should be (800 - 2y)
}

UIMainView = Viewports.Center
GROUND_MAIN_VIEWPORT = Viewports.Center