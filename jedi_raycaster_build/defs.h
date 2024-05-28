#ifndef DEFS_H
#define DEFS_H


#define PI     3.14159265f
#define TWO_PI 6.28318530f

#define STRETCHED_TEXTURING false
#define MULTIPLE_LEVELS     true
#define RENDER_CEILING      !MULTIPLE_LEVELS

#define WINDOW_WIDTH  600
#define WINDOW_HEIGHT 420

#define MAP_NUM_ROWS_Y 14
#define MAP_NUM_COLS_X 20
#define MAXHEIGHT 4
#define TILE_SIZE 64

#define MINIMAP_SCALE_FACTOR 0.1   // should be 0.1

#define NUM_TEXTURES 14

#define TEXTURE_WIDTH 64
#define TEXUTRE_HEIGHT 64

#define NUM_SPRITES 3
#define FOV_ANGLE (60 * (PI / 180))

#define NUM_RAYS WINDOW_WIDTH
//640               .5775
#define DIST_TO_PROJ_PLANE ((WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2)) //1108.51


const int FPS = 60;
const int MILLISECS_PER_FRAME = 1000 / FPS;
const int PIXELS_PER_METER = 50;


#define FPS 60
#define FRAME_TIME_LENGTH (1000 / FPS)

#define GRND_FLOOR '.'     // no block
#define FRST_FLOOR '#'     // block of height 1
#define SCND_FLOOR '@'     //                 2
#define THRD_FLOOR '*'     //                 3
#define FRTH_FLOOR '-'     //                 4
#define FFTH_FLOOR '+'     //                 5
#define SXTH_FLOOR '='     //                 6

#define FLOOR_1QRTR 'Q'    // block of height 1/4
#define FLOOR_HALVE 'H'    //                 2/4
#define FLOOR_3QRTR 'T'   //                 3/4

#define TEXTURE_BLANK '.'
#define TEXTURE_ZERO '0'
#define TEXTURE_ONE '1'
#define TEXTURE_TWO '2'
#define TEXTURE_THREE '3'
#define TEXTURE_FOUR '4'
#define TEXTURE_FIVE '5'

#endif // #ifndef DEFS_H
