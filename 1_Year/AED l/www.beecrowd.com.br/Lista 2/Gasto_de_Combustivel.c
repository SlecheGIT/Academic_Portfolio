#include <stdio.h>
 
int main() {
 int t, kmh;
 float kml=12;
 
  scanf("%i",&t);
  scanf("%i",&kmh);
 
 kml= (kmh * t) / kml;
    printf("%.3f\n", kml);

    return 0;
}
 /*
10
85
---
70.833

2
92
---
15.333

22
67
---
122.833
*/