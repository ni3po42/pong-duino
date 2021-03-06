//Timothy Stratton

#define COLORPIN0 7
#define HSYNCPIN 3
#define VSYNCPIN 9

//initial blanks lines to skip
#define VSKIP 30

#define ROWS 118
#define COLS 128

#define PADDLESIZE 16
#define PADDLEOFFSET 8
#define PADDBOTT (ROWS - PADDLESIZE - 1)

#define LINE_SIZE 16
#define SIZE (LINE_SIZE * ROWS)

#define H_BLANK_START 266 //2 * rows + vskip

//video memory:
//each byte represents 8 pixels. No color: just on or off
//memory is preloaded with game field
byte g[SIZE] = {
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF  
  };

struct scratch_t {
  int a;
  int b;
} scratch;

struct ball_t {
  byte x: 8;
  byte y: 8;
  signed char deltaX: 4;
  signed char deltaY: 4;
  byte dispBuff;
} ball;

struct player_t {
  byte pos: 7;
  byte score: 4;
  long input;
  signed char moment: 3;
} player1, player2;

struct conditions_t {
  bool wallHit: 1;
  bool leftPaddleHit: 1;
  bool rightPaddleHit: 1;
  bool leftWallHit: 1;
  bool rightWallHit: 1;  
} conditions;

unsigned vpulse;
byte wait = 0;
byte soundDelay = 0;
unsigned afreq, afreq0;

inline void setBall() {  
  scratch.a = (ball.y * COLS) + ball.x;
  scratch.b = scratch.a >> 3;  
  ball.dispBuff = g[scratch.b];
  g[scratch.b] |= 1 << (7 - (scratch.a % 8));  
}

inline void clearBall() {    
  g[((ball.y * COLS) + ball.x) >> 3] = ball.dispBuff;      
}

inline void clearScores() {
  g[2] = 0xFF;
  g[3] = 0xFF;
  g[4] = 0xFF;
  g[((COLS/8) - 4)] = 0xFF;
  g[((COLS/8) - 3)] = 0xFF;
  g[((COLS/8) - 2)] = 0xFF;
}

inline void displayScore() {  
  if (player1.score != 0) {
    switch((player1.score - 1) % 4) {
      case 0: g[2 + ((player1.score - 1) / 4)] = 0x7f; break;
      case 1: g[2 + ((player1.score - 1) / 4)] = 0x5f; break;
      case 2: g[2 + ((player1.score - 1) / 4)] = 0x57; break;
      case 3: g[2 + ((player1.score - 1) / 4)] = 0x55; break;
    }
  }

  if (player2.score != 0) {
    switch((player2.score - 1) % 4) {
      case 0: g[((COLS/8) - 4) + ((player2.score - 1) / 4)] = 0x7f; break;
      case 1: g[((COLS/8) - 4) + ((player2.score - 1) / 4)] = 0x5f; break;
      case 2: g[((COLS/8) - 4) + ((player2.score - 1) / 4)] = 0x57; break;
      case 3: g[((COLS/8) - 4) + ((player2.score - 1) / 4)] = 0x55; break;
    }
  }
}


inline void setPlayers() {  
    scratch.a = ((int)player1.pos * (int)COLS) + PADDLEOFFSET;
    scratch.b = scratch.a >> 3;  
    scratch.a = 1 << (7 - (scratch.a % 8));
  
    scratch.b += LINE_SIZE;
    g[scratch.b] |= scratch.a;
    scratch.b += LINE_SIZE;
    g[scratch.b] |= scratch.a;
    scratch.b += LINE_SIZE;
    g[scratch.b] |= scratch.a;
    scratch.b += LINE_SIZE;
    g[scratch.b] |= scratch.a;
    scratch.b += LINE_SIZE;
    g[scratch.b] |= scratch.a;
    scratch.b += LINE_SIZE;
    g[scratch.b] |= scratch.a;
    scratch.b += LINE_SIZE;
    g[scratch.b] |= scratch.a;
    scratch.b += LINE_SIZE;
    g[scratch.b] |= scratch.a;
    scratch.b += LINE_SIZE;
    g[scratch.b] |= scratch.a;
    scratch.b += LINE_SIZE;
    g[scratch.b] |= scratch.a;
    scratch.b += LINE_SIZE;
    g[scratch.b] |= scratch.a;
    scratch.b += LINE_SIZE;
    g[scratch.b] |= scratch.a;
    scratch.b += LINE_SIZE;
    g[scratch.b] |= scratch.a;
    scratch.b += LINE_SIZE;
    g[scratch.b] |= scratch.a;
    scratch.b += LINE_SIZE;
    g[scratch.b] |= scratch.a;
    scratch.b += LINE_SIZE;
    g[scratch.b] |= scratch.a;

    scratch.a = ((int)player2.pos * (int)COLS) + (COLS - PADDLEOFFSET - 1);
    scratch.b = scratch.a >> 3;  
    scratch.a = 1 << (7 - (scratch.a % 8));

    scratch.b += LINE_SIZE;
    g[scratch.b] |= scratch.a;
    scratch.b += LINE_SIZE;
    g[scratch.b] |= scratch.a;
    scratch.b += LINE_SIZE;
    g[scratch.b] |= scratch.a;
    scratch.b += LINE_SIZE;
    g[scratch.b] |= scratch.a;
    scratch.b += LINE_SIZE;
    g[scratch.b] |= scratch.a;
    scratch.b += LINE_SIZE;
    g[scratch.b] |= scratch.a;
    scratch.b += LINE_SIZE;
    g[scratch.b] |= scratch.a;
    scratch.b += LINE_SIZE;
    g[scratch.b] |= scratch.a;
    scratch.b += LINE_SIZE;
    g[scratch.b] |= scratch.a;
    scratch.b += LINE_SIZE;
    g[scratch.b] |= scratch.a;
    scratch.b += LINE_SIZE;
    g[scratch.b] |= scratch.a;
    scratch.b += LINE_SIZE;
    g[scratch.b] |= scratch.a;
    scratch.b += LINE_SIZE;
    g[scratch.b] |= scratch.a;
    scratch.b += LINE_SIZE;
    g[scratch.b] |= scratch.a;
    scratch.b += LINE_SIZE;
    g[scratch.b] |= scratch.a;
    scratch.b += LINE_SIZE;
    g[scratch.b] |= scratch.a;
}  

inline void clearPlayers() {
    scratch.a = ((int)player1.pos * (int)COLS) + PADDLEOFFSET;
    scratch.b = scratch.a >> 3;  

    scratch.b += LINE_SIZE;
    g[scratch.b] = 0;
    scratch.b += LINE_SIZE;
    g[scratch.b] = 0;
    scratch.b += LINE_SIZE;
    g[scratch.b] = 0;
    scratch.b += LINE_SIZE;
    g[scratch.b] = 0;
    scratch.b += LINE_SIZE;
    g[scratch.b] = 0;
    scratch.b += LINE_SIZE;
    g[scratch.b] = 0;
    scratch.b += LINE_SIZE;
    g[scratch.b] = 0;
    scratch.b += LINE_SIZE;
    g[scratch.b] = 0;
    scratch.b += LINE_SIZE;
    g[scratch.b] = 0;
    scratch.b += LINE_SIZE;
    g[scratch.b] = 0;
    scratch.b += LINE_SIZE;
    g[scratch.b] = 0;
    scratch.b += LINE_SIZE;
    g[scratch.b] = 0;
    scratch.b += LINE_SIZE;
    g[scratch.b] = 0;
    scratch.b += LINE_SIZE;
    g[scratch.b] = 0;
    scratch.b += LINE_SIZE;
    g[scratch.b] = 0;
    scratch.b += LINE_SIZE;
    g[scratch.b] = 0;
    
    scratch.a = ((int)player2.pos * (int)COLS) + (COLS - PADDLEOFFSET - 1);
    scratch.b = scratch.a >> 3;  

    scratch.b += LINE_SIZE;
    g[scratch.b] = 0;
    scratch.b += LINE_SIZE;
    g[scratch.b] = 0;
    scratch.b += LINE_SIZE;
    g[scratch.b] = 0;
    scratch.b += LINE_SIZE;
    g[scratch.b] = 0;
    scratch.b += LINE_SIZE;
    g[scratch.b] = 0;
    scratch.b += LINE_SIZE;
    g[scratch.b] = 0;
    scratch.b += LINE_SIZE;
    g[scratch.b] = 0;
    scratch.b += LINE_SIZE;
    g[scratch.b] = 0;
    scratch.b += LINE_SIZE;
    g[scratch.b] = 0;
    scratch.b += LINE_SIZE;
    g[scratch.b] = 0;
    scratch.b += LINE_SIZE;
    g[scratch.b] = 0;
    scratch.b += LINE_SIZE;
    g[scratch.b] = 0;
    scratch.b += LINE_SIZE;
    g[scratch.b] = 0;
    scratch.b += LINE_SIZE;
    g[scratch.b] = 0;
    scratch.b += LINE_SIZE;
    g[scratch.b] = 0;
    scratch.b += LINE_SIZE;
    g[scratch.b] = 0;
}

//calling random more than once either takes
//too many cycles or adds too much to stack
//and causes things to crash. Only call random
//once and extract all values need. This means
//delta and pos data are related; ok compromise
inline void randBall() {
  ball.x = 64;
  ball.y = random(1, ROWS);  
  ball.deltaX = (ball.y & 0x02) - 1;
  ball.deltaY = ((ball.y & 0x08) >> 2) - 1;  
}

inline void setupGame() {
  clearBall();
  randBall();
  player1.score = 0;
  player2.score = 0;
  clearScores();
}

inline void startGameSound() { 
  soundDelay = 255; 
  afreq = 8000;
  afreq0 = afreq;
}

inline void paddleHitSound() {
  soundDelay = 10; 
  afreq = 16394;
  afreq0 = afreq;
}

inline void wallHitSound() {
  soundDelay = 10; 
  afreq = 800;
  afreq0 = afreq;
}

inline void scoreSound() {
  soundDelay = 30;
  afreq = 600;
  afreq0 = afreq;
}

inline void gameEndSound() {
  soundDelay = 120;
  afreq = 8000;
  afreq0 = afreq;
}

inline void noSound() {
  afreq = 0;
  afreq0 = afreq;
}

inline void configTimers() {
  cli();     
  //disable TIMER0 interrupt
  TIMSK0=0;
  TCCR0A=0;
  TCCR0B=(1 << CS00); //enable 16MHz counter (used to fix the HSYNC interrupt jitter)
  OCR0A=0;
  OCR0B=0;
  TCNT0=0;
  
  //disable TIMER1 interrupt
  TCCR1A=0;
  TCCR1B=0; 
  ICR1=0;
  OCR1A=0;  
  TIFR1=0;
  TIMSK1=0;
  
  //TIMER2 - horizontal sync pulses  
  TCCR2A=bit(WGM20) | bit(WGM21) | bit(COM2B1); //pin3=COM2B1
  TCCR2B=bit(WGM22) | bit(CS21); //8 prescaler
  OCR2A=122;//16260hz ==> (16000000 / (8 * 16260hz)) - 1  
  OCR2B=7; //pulse width - 4us = (7 + 1) / 2 ==> 7
  TIFR2=bit(TOV2); //clear overflow flag
  TIMSK2=bit(TOIE2); //interrupt on overflow on TIMER2

  sei();
}

void setup() {
  vpulse = 0;
  
  pinMode(16, OUTPUT);
  pinMode(VSYNCPIN, OUTPUT);  
  pinMode(HSYNCPIN, OUTPUT);  
  pinMode(COLORPIN0, OUTPUT); 

  PORTD = 0x00;
  //set random number generator
  //seed to noise from analog pin
  randomSeed(analogRead(3));

  noSound();
  wait = 255;
    
  configTimers();
  setupGame();
  startGameSound();

  //first byte of video memory 
  //kept getting set to 0x00,
  //this is cheap fix
  g[0]=0xFF;
}

inline void sound() {
//borrowed most audio implmentation from
//https://github.com/smaffer/vgax  
//10 cycles
asm volatile(                                   //4c to load Z and Y
    "      ld r16, Z                        \n\t" //c1 r16=afreq
    "      cpi %[freq0], 0                  \n\t" //c1 afreq0==0 ?
    "      breq no_audio                    \n\t" //c1/2 *0
    "play_audio:                            \n\t" 
    "      cpi r16, 0                       \n\t" //c1 afreq==0 ?
    "      brne dont_flip_audio_pin         \n\t" //c1/2 *1
    "flip_audio_pin:                        \n\t" 
    "      ldi r18, 4                       \n\t" //c1
    "      out %[audiopin], r18             \n\t" //c1
    "      st Z, %[freq0]                   \n\t" //c1 afreq=afreq0
    "      rjmp end                         \n\t" //c2
    "no_audio:                              \n\t" 
    "      nop                              \n\t" //c1
    "      nop                              \n\t" //c1
    "      nop                              \n\t" //c1
    "      nop                              \n\t" //c1
    "      rjmp end                         \n\t" //c2
    "dont_flip_audio_pin:                   \n\t" 
    "      dec r16                          \n\t" //c1
    "      st Z, r16                        \n\t" //c1
  "      nop                              \n\t" //c1
    "      nop                              \n\t" //c1
    "end:                                   \n\t"
  :
  : "z" (&afreq),
    [freq0] "r" (afreq0),
    [audiopin] "i" _SFR_IO_ADDR(PINC)
  : "r16", "r18");
}

//game code is broken up in to small executable chunks,
//and are executed in the blank horizontal lines to 
//avoid interferring with data pulses.
ISR(TIMER2_OVF_vect) {

  //attempt to run sound every horizontal line
  sound();

  if (vpulse == 1) { 
    //using 1 timer to simulate 2 signals
    //to help keep them in sync. Start
    //rising edge   
    PORTB = 0x02;
  } else if (vpulse == 3) {
    //get inputs player1
    scratch.a = analogRead(A0);
    player1.moment = (scratch.a - player1.input) / 16;
    player1.input = scratch.a;
    
  } else if (vpulse == 4) {
    //calc momentum player 1
    if (player1.moment > 0) {
      player1.moment = player1.moment & 0x03;      
    } else if (player1.moment < 0) {
      player1.moment = -((-player1.moment) & 0x03);
    }
    
  } else if (vpulse == 5) {
    //get inputs player2
    scratch.a = analogRead(A1);
    player2.moment = (scratch.a - player2.input) / 16;
    player2.input = scratch.a;
    
  } else if (vpulse == 6) {
    //start falling edge
    PORTB = 0x00;
    //calc momentum player 2
    if (player2.moment > 0) {
      player2.moment = player2.moment & 0x03;      
    } else if (player1.moment < 0) {
      player2.moment = -((-player2.moment) & 0x03);
    }
  } else if (vpulse == 7) { 
    clearBall();
  } else if (vpulse == 8) { 
    clearPlayers();   
  } else if (vpulse == 9) {         
    //position players
    player1.pos = (byte)(((player1.input) * 100) / 1023);
    player2.pos = (byte)(((player2.input) * 100) / 1023);    
  } else if (vpulse == 10) {
    conditions.wallHit = ball.y+ball.deltaY >= ROWS || ball.y+ball.deltaY <= 0;
  } else if (vpulse == 11) {
    conditions.leftPaddleHit = ball.x == (PADDLEOFFSET + 1) && (ball.y >= player1.pos-1 && ball.y < (player1.pos + PADDLESIZE+1));
  } else if (vpulse == 12) {
    conditions.rightPaddleHit = ball.x == (COLS - PADDLEOFFSET - 1) && (ball.y >= player2.pos-1 && ball.y < (player2.pos + PADDLESIZE+1));
  } else if (vpulse == 13) {
    conditions.leftWallHit = ball.x+ball.deltaX <= 0;
  } else if (vpulse == 14) {
    conditions.rightWallHit = ball.x+ball.deltaX >= COLS-1;   
  } else if (vpulse == 15) {
    //apply updates for paddle hits
    if (conditions.leftPaddleHit) {
      ball.deltaX = -ball.deltaX;
      ball.deltaY = ball.deltaY + player1.moment;
      paddleHitSound();    
    } else if (conditions.rightPaddleHit) {
      ball.deltaX = -ball.deltaX;
      ball.deltaY = ball.deltaY + player2.moment;
      paddleHitSound();    
    }
    
  } else if (vpulse == 16) {
    //apply updates for top/bottom wall hits    
    if (conditions.wallHit) {
      ball.deltaY = -ball.deltaY;
      wallHitSound();
    }

  } else if (vpulse == 17) {
    //apply updates for left/right wall hits
    if(conditions.leftWallHit || conditions.rightWallHit) {
      ball.deltaX = -ball.deltaX;
      
      if(conditions.leftWallHit) {
        player2.score++;
      } else {    
        player1.score++;            
      }
      displayScore();
    }
  } else if (vpulse == 18) {  
    //check for next round or next game
    if(conditions.leftWallHit || conditions.rightWallHit) {
      if (player1.score == 10 || player2.score == 10) {
        setupGame();
        gameEndSound();        
      } else {  
        scoreSound();              
        randBall();
      }
      wait = soundDelay;
    }

  } else if (vpulse == 19) {
    //apply updates to ball  
    if (wait <= 0) {
      ball.x += ball.deltaX;
      ball.y += ball.deltaY;
    }
  } else if (vpulse == 20) {  
    setBall(); 
  } else if (vpulse == 21) {
    setPlayers();        
  } else if (vpulse == 271) {
    //last horizontal line; reset counter
    //to start at top again
    vpulse = 0;

    //check for line waits
    if (wait > 0){
      wait--;
    } 

    //check for pitch holds
    if (soundDelay > 0) {
      soundDelay--;
    }

    //if no length for pitch hold,
    //play no sound
    if (soundDelay == 0) {
      noSound();
    }    
  } else if (vpulse >= VSKIP && vpulse < H_BLANK_START) {
    //non-blank lines for video
    
    //dejitter borrowed from
    //https://github.com/smaffer/vgax
    #define DEJITTER_OFFSET 1
    #define DEJITTER_SYNC -2
    asm volatile(
      "     lds r16, %[timer0]    \n\t" //   
      "     subi r16, %[tsync]    \n\t" //
      "     andi r16, 7           \n\t" //
      "     call TL               \n\t" //
      "TL:                        \n\t" //    
      "     pop r31               \n\t" //
      "     pop r30               \n\t" //
      "     adiw r30, (LW-TL-5)   \n\t" //
      "     add r30, r16          \n\t" //
      "     ijmp                  \n\t" //
      "LW:                        \n\t" //
      "     nop                   \n\t" //
      "     nop                   \n\t" //
      "     nop                   \n\t" //
      "     nop                   \n\t" //
      "     nop                   \n\t" //
      "     nop                   \n\t" //
      "     nop                   \n\t" //

      "LBEND:                     \n\t" //
    :
    : [timer0] "i" (&TCNT0),
      [toffset] "i" ((uint8_t)DEJITTER_OFFSET),
      [tsync] "i" ((uint8_t)DEJITTER_SYNC)
    : "r30", "r31", "r16", "r17");

    //store 'row' to get next line for render
    //pixels are fat and short, so we render 
    //a line twice to make it more square
    scratch.a = ((vpulse - VSKIP) >> 1)*LINE_SIZE;

    //inspired by:
    //https://github.com/smaffer/vgax
    //5 cycles per bit
    //load byte to pulse out 8 pixels.
    //on 7th pixel, preload next byte
      asm volatile (
        ".rept 15               \n\t"//71
          "nop                  \n\t"
        ".endr                  \n\t"
        "ld r16, Z+             \n\t"//2
        ".rept 16             \n\t"         
          "out %[port], r16   \n\t"//1
          ".rept 6            \n\t"              
            "lsl r16          \n\t"//1      
            "mov r20, r16     \n\t"//1           
            "lsl r20          \n\t"//1
            "nop              \n\t"//1
            "out %[port], r16 \n\t"//1      
          ".endr              \n\t"           
          "ld r16, Z+         \n\t"//2
          "nop                \n\t"//1
          "nop                \n\t"//1
          "out %[port], r20   \n\t"//1  
          "ldi r20, 0         \n\t"//1
          "nop                \n\t"//1      
          "nop                \n\t"//1      
          "nop                \n\t"//1               
        ".endr                \n\t"//1                   
        "out %[port], r20     \n\t"//1 
        "nop                  \n\t"//1
        "nop                  \n\t"//1
        "nop                  \n\t"//1
        "nop                  \n\t"//1      
      :  
      : [port] "I" (_SFR_IO_ADDR(PORTD)),  
        "z" "I" ((byte*)g + scratch.a)
      : "r16", "r20", "memory"
      ); 
  }

  //increment to next horizontal line
  vpulse++;
}

//not used; interferes with timer interupt
void loop() {
}
