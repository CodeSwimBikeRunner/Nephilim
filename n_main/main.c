#include "../n_render/render.h"
#include "stdio.h"
#include "stdlib.h"

int main(int argc, const char *argv[])
{
  RenderPtr render = render_init(640, 640);
  
  render_loop(render);

  render_quit(render);
  return 0;
}