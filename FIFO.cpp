#include <stdio.h>
#define MAX_PAGE_FRAMES 3
#define MAX_PAGE_REFERENCE_SEQUENCE 8

int main() {
  int page_frames[MAX_PAGE_FRAMES];
  int page_reference_sequence[MAX_PAGE_REFERENCE_SEQUENCE] = {4, 1, 2, 4, 3, 2, 1, 5};
  int page_faults = 0;
  int page_frame_pointer = 0;

 
  for (int i = 0; i < MAX_PAGE_FRAMES; i++) {
    page_frames[i] = -1;
  }


  for (int i = 0; i < MAX_PAGE_REFERENCE_SEQUENCE; i++) {
    int page_reference = page_reference_sequence[i];
    int page_frame_found = 0;

    for (int j = 0; j < MAX_PAGE_FRAMES; j++) {
      if (page_frames[j] == page_reference) {
        page_frame_found = 1;
        break;
      }
    }

    if (!page_frame_found) {
      page_frames[page_frame_pointer] = page_reference;
      page_frame_pointer = (page_frame_pointer + 1) % MAX_PAGE_FRAMES;
      page_faults++;
    }
  }

  printf("Number of page faults: %d\n", page_faults);

  return 0;
}
