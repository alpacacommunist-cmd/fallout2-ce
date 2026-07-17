#ifndef COLOR_H
#define COLOR_H

namespace fallout { 

typedef unsigned char Color;
typedef const char*(ColorFileNameManger)(const char*);
typedef void(ColorTransitionCallback)();

extern unsigned char _cmap[768];

extern unsigned char _systemCmap[256 * 3];
extern unsigned char _currentGammaTable[64];
extern unsigned char* _blendTable[256];
extern unsigned char _mappedColor[256];
extern Color colorMixAddTable[256][256];
extern Color intensityColorTable[256][256];
extern Color colorMixMulTable[256][256];
extern unsigned char _colorTable[32768];

int _calculateColor(int intensity, Color color);
int Color2RGB(Color c);
void colorPaletteFadeBetween(unsigned char* oldPalette, unsigned char* newPalette, int steps);
void colorPaletteSetTransitionCallback(ColorTransitionCallback* callback);
void _setSystemPalette(unsigned char* palette);
unsigned char* _getSystemPalette();
void _setSystemPaletteEntries(unsigned char* palette, int start, int end);
bool colorPaletteLoad(const char* path);
char* _colorError();
unsigned char* _getColorBlendTable(int ch);
void _freeColorBlendTable(int color);
void colorSetBrightness(double value);
bool _initColors();
void _colorsClose();

#define COLOR_LIGHT_RED _colorTable[32074]
#define COLOR_RED _colorTable[31744]
#define COLOR_RED_2 _colorTable[28672]
#define COLOR_DARK_RED _colorTable[23624]

#define COLOR_WHITE _colorTable[32767]
#define COLOR_WHITE_2 _colorTable[25439]

#define COLOR_LIGHT_GREY _colorTable[21140]
#define COLOR_LIGHT_GREY_2 _colorTable[20052]
#define COLOR_GREY _colorTable[17969]
#define COLOR_GREY_2 _colorTable[15855]
#define COLOR_DARK_GREY _colorTable[8456]
#define COLOR_DARK_GREY_2 _colorTable[10570]
#define COLOR_DARK_GREY_3 _colorTable[4228]

#define COLOR_BLACK _colorTable[0]
#define COLOR_BLACK_2 _colorTable[2]

#define COLOR_LIGHT_PURPLE _colorTable[10239]
#define COLOR_LIGHT_BLUE _colorTable[6513]
#define COLOR_BLUE _colorTable[31]
#define COLOR_BLUE_2 _colorTable[21]
#define COLOR_DULL_BLUE _colorTable[18161]

#define COLOR_LIGHT_PINK _colorTable[32239]
#define COLOR_PINK _colorTable[31775]
#define COLOR_DULL_PINK _colorTable[31215]

#define COLOR_LIGHT_GREEN _colorTable[448]
#define COLOR_LIGHT_GREEN_2 _colorTable[8804]
#define COLOR_LIGHT_GREEN_3 _colorTable[768]
#define COLOR_GREEN _colorTable[992]
#define COLOR_DARK_GREEN _colorTable[480]
#define COLOR_DARK_GREEN_2 _colorTable[1313]
#define COLOR_GRASS_GREEN _colorTable[15845]

#define COLOR_LIGHT_YELLOW _colorTable[32747]
#define COLOR_LIGHT_GOLD _colorTable[31650]
#define COLOR_LIGHT_GOLD_2 _colorTable[30632]
#define COLOR_YELLOW _colorTable[32328]
#define COLOR_YELLOW_2 _colorTable[21091]
#define COLOR_SAND _colorTable[22025]
#define COLOR_GOLD _colorTable[30689]
#define COLOR_DARK_YELLOW _colorTable[18979]
#define COLOR_DARK_YELLOW_2 _colorTable[14723]
#define COLOR_DARK_YELLOW_3 _colorTable[18917]
#define COLOR_DARK_YELLOW_4 _colorTable[18977]
#define COLOR_DULL_YELLOW _colorTable[32495]

#define COLOR_LIGHT_BROWN _colorTable[12546]
#define COLOR_LIGHT_BROWN_2 _colorTable[22187]
#define COLOR_DULL_BROWN _colorTable[13673]

} // namespace fallout

#endif /* COLOR_H */
