#include <stdio.h>
#define MAX_PAGE_FRAMES 3

int page_frames[MAX_PAGE_FRAMES];
int page_count = 0;
int page_faults = 0;

int check_page_hit(int page_number) {
  for (int i = 0; i < MAX_PAGE_FRAMES; i++) {
    if (page_frames[i] == page_number) {
      return i;
    }
  }
  return -1;
}

void update_page_frames(int page_number) {
  page_faults++;
  int page_hit = check_page_hit(page_number);
  if (page_hit != -1) {
    for (int i = page_hit; i < page_count - 1; i++) {
      page_frames[i] = page_frames[i + 1];
    }
    page_frames[page_count - 1] = page_number;
  } else {
    if (page_count < MAX_PAGE_FRAMES) {
      page_frames[page_count++] = page_number;
    } else {
      for (int i = 0; i < MAX_PAGE_FRAMES - 1; i++) {
        page_frames[i] = page_frames[i + 1];
      }
      page_frames[MAX_PAGE_FRAMES - 1] = page_number;
    }
  }
}

int main() {
  int page_reference_sequence[] = {1, 2, 3, 2, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3, 6, 1, 2, 4, 3};
  int page_reference_sequence_length = sizeof(page_reference_sequence) / sizeof(page_reference_sequence[0]);

  for (int i = 0; i < page_reference_sequence_length; i++) {
    update_page_frames(page_reference_sequence[i]);
  }

  printf("Total number of page faults: %d\n", page_faults);
  return 0;
}
