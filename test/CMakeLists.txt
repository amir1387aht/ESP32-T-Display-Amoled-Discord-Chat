SET(SOURCES screens/ui_Setting.c
    screens/ui_Setting1.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    ui_events.c
    images/ui_img_364238874.c
    fonts/ui_font_gg_sans_bold.c
    fonts/ui_font_gg_sans_small.c)

add_library(ui ${SOURCES})
