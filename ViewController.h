//
//  ViewController.h
//  FinalFourFearsomeFantasy
//
//  Created by Kyle Koser on 4/8/14.
//  Copyright (c) 2014 Kyle Koser. All rights reserved.
//

#ifndef __FinalFourFearsomeFantasy__ViewController__
#define __FinalFourFearsomeFantasy__ViewController__

#include <iostream>
#include <iostream>
#include <SDL2/SDL.h>
#include "SDL2_image/SDL_image.h"
#include "SDL2_ttf/SDL_ttf.h"
#include "SDL2_mixer/SDL_mixer.h"
#include <string>
#include <vector>
#include "LTexture.h"
#include "Settings.h"

class ViewController {
protected:
    SDL_Renderer *renderer;

public:
    ViewController(SDL_Window *win);
    void dismiss();
    ~ViewController();
};

#endif /* defined(__FinalFourFearsomeFantasy__ViewController__) */
