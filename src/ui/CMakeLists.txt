SET(SOURCES screens/ui_BotKeyScreen.c
    screens/ui_Setting_Screen.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    ui_events.c
    images/ui_img_1102433829.c
    images/ui_img_discord_com_login_normal_png.c
    images/ui_img_592994106.c
    images/ui_img_2024208504.c
    images/ui_img_1746740777.c
    fonts/ui_font_gg_sans_bold.c
    fonts/ui_font_gg_sans_small.c)

add_library(ui ${SOURCES})
