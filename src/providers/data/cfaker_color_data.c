#include "providers/data/cfaker_color_data.h"

static const char* names_en_US[] = {
    "azure",    "black",  "blue",     "cyan",      "fuchsia", "gold",   "green",      "grey",
    "indigo",   "ivory",  "lavender", "lime",      "magenta", "maroon", "mint green", "olive",
    "orange",   "orchid", "pink",     "plum",      "purple",  "red",    "salmon",     "silver",
    "sky blue", "tan",    "teal",     "turquoise", "violet",  "white",  "yellow",
};

const struct cfaker_color cfaker_color_en_US = {
    .names = names_en_US,
    .name_count = sizeof(names_en_US) / sizeof(names_en_US[0]),
};

static const char* names_zh_CN[] = {
    "蔚蓝",   "黑色",   "蓝色",   "青色",   "紫红色", "金色",     "绿色",     "灰色",   "靛蓝",   "象牙白", "薰衣草紫",
    "莱姆绿", "品红色", "栗色",   "薄荷绿", "橄榄色", "橙色",     "兰花紫",   "粉红色", "李子紫", "紫色",   "红色",
    "鲑鱼色", "银色",   "天空蓝", "棕褐色", "水鸭色", "绿松石色", "紫罗兰色", "白色",   "黄色",
};

const struct cfaker_color cfaker_color_zh_CN = {
    .names = names_zh_CN,
    .name_count = sizeof(names_zh_CN) / sizeof(names_zh_CN[0]),
};