#include "../n_render/render.h"
#include "stdio.h"
#include "stdlib.h"
#include "../WinThread/include/pthread.h"

int g = 0; 
  
// The function to be executed by all threads 
void *myThreadFun(void *vargp) 
{ 
    // Store the value argument passed to this thread 
    int *myid = (int *)vargp; 
  
    // Let us create a static variable to observe its changes 
    static int s = 0; 
  
    // Change static and global variables 
    ++s; ++g; 
  
    // Print the argument, static and global variables 
    printf("Thread ID: %d, Static: %d, Global: %d\n", *myid, ++s, ++g); 
} 

int main(int argc, const char *argv[])
{
  int i; 
  pthread_t tid; 
  
    // Let us create three threads 
  for (i = 0; i < 3; i++) 
      pthread_create(&tid, NULL, myThreadFun, (void *)&tid); 
  
  RenderPtr render = render_init(640, 640);
  
  render_loop(render);

  render_quit(render);
  return 0;
}