static const char* valid_background_scene =
"................................................................\n"
"|                                                              |\n"
"|                 TTTTT  EEEE    SSS  TTTTT                    |\n"
"|                   T    E      S       T                      |\n"
"|                   T    EEEE    SS     T                      |\n"
"|                   T    E         S    T                      |\n"
"|                   T    EEEE   SSS     T                      |\n"
"................................................................\n";

static const char* invalid_background_with_newlines_on_different_columns= 
".....\n"
".........\n"
"....\n";
static const char* invalid_background_with_no_newlines= 
"......\t............"
"..............\r....";

static int expected_scene_width = 64;
static int expected_scene_height = 8;

static const char* scene_object = "@";
