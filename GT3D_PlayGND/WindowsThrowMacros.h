#pragma once

#define GTWND_EXCEPT( hr ) Window::HrException( __LINE__,__FILE__,(hr) )
#define GTWND_LAST_EXCEPT() Window::HrException( __LINE__,__FILE__,GetLastError() )
#define GTWND_NOGFX_EXCEPT() Window::NoGfxException( __LINE__,__FILE__ )
