#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
#    if defined(ENABLE_RGB_MATRIX_SOLID_SPLASH_BLACK) || defined(ENABLE_RGB_MATRIX_SOLID_MULTISPLASH_BLACK)

#        ifdef ENABLE_RGB_MATRIX_SOLID_SPLASH_BLACK
RGB_MATRIX_EFFECT(SOLID_SPLASH_BLACK)
#        endif

#        ifdef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH_BLACK
RGB_MATRIX_EFFECT(SOLID_MULTISPLASH_BLACK)
#        endif

#        ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

HSV SOLID_SPLASH_BLACK_math(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick) {
    uint16_t effect = tick - dist;
    if (effect > 255) effect = 255;
    hsv.v = qadd8(hsv.v, 255 - effect);
    return hsv;
}

#            ifdef ENABLE_RGB_MATRIX_SOLID_SPLASH_BLACK
bool SOLID_SPLASH_BLACK(effect_params_t* params) {
    return effect_runner_reactive_splash_BLACK(qsub8(g_last_hit_tracker.count, 1), params, &SOLID_SPLASH_BLACK_math);
}
#            endif

#            ifdef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH_BLACK
bool SOLID_MULTISPLASH_BLACK(effect_params_t* params) {
    return effect_runner_reactive_splash_BLACK(0, params, &SOLID_SPLASH_BLACK_math);
}
#            endif

#        endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#    endif     // !defined(ENABLE_RGB_MATRIX_SPLASH_BLACK) && !defined(ENABLE_RGB_MATRIX_MULTISPLASH_BLACK)
#endif         // RGB_MATRIX_KEYREACTIVE_ENABLED
