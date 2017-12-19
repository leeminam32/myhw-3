#include <sys/types.h>
#include <limits.h>

#include "run.h"
#include "util.h"

void *base = 0;

p_meta find_meta(p_meta *last, size_t size) {
  p_meta index = base;
  p_meta result = base;

  switch(fit_flag){
    case FIRST_FIT:
    {
      //FIRST FIT CODE
    	while(index != NULL){
    		if ( index->free != 0 && index->size >= size) break;
    		
    		index = index -> next;
    	}
    	result = index;
    }
    break;

    case BEST_FIT:
    {
      //BEST_FIT CODE
    	p_meta best = index ;
    	while(index != NULL){
    		if (index -> free != 0 && index->size >=size)
    		{
    			if (index->size <= best->size)
    			{
    				best = index;
    			}
    		}
    	}
    	result = best;
    }
    break;

    case WORST_FIT:
    {
      //WORST_FIT CODE
    	p_meta worst = index;
    	while(index != NULL){
    		if (index -> free != 0 && index->size >= size)
    		{
    			if (index->size >worst->size)
    			{
    				worst = index;
    			}
    		}
    	}
    	result = worst;
    }
    break;

  }
  return result;
}

void *m_malloc(size_t size) {

}

void m_free(void *ptr) {

}

void*
m_realloc(void* ptr, size_t size)
{

}
