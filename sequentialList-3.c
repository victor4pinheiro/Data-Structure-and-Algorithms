#include <stdio.h>
#define MAX_PHOTOS 1000;

typedef int KEY_PHOTO;

typedef struct {
  KEY_PHOTO value;
  char name[255], extension[4], datetime[10];
} PHOTO_DATA;

typedef struct {
  PHOTO_DATA PHOTO[MAX_PHOTOS];
  int numberPhotos;
} STORAGE_PHOTOS;

void startStorePhotos(STORAGE_PHOTOS* storage) {
  storage->numberPhotos = 0;
}

int showNumberPhotos(STORAGE_PHOTOS* storage) {
  return storage->numberPhotos;
}

void showPhotos(STORAGE_PHOTOS* storage) {
  int count;
  printf("Start: \n");

  for (count = 0; count < storage->numberPhotos; count+) {
    printf("Photo %i \n", storage->PHOTO[count].value);
  }

  printf("End");

}
 

int searchPhoto(STORAGE_PHOTOS* storage, KEY_TYPE id) {
  int countSearch;

  while (countSearch < storage->numberPhotos) {
    if(id == storage->PHOTO[countSearch].value) {
      return countSearch;
    } else {
      countSearch++;
    }
  }
   
 return -1;

}

int takePhoto(STORAGE_PHOTOS* storage, PHOTO_DATA sendPhoto, int countCondition) {
  int countHandleStorage;

  if ((storage->numberPhotos == MAX_PHOTOS) || (countCondition < 0) || countCondition > storage->numberPhotos) {
    return 0;
  }

  for (countHandleStorage = storage->numberPhotos; countHandleStorage > countCondition; countHandleStorage--) {
    storage->PHOTO[countHandleStorage] = storage->PHOTO[countHandleStorage - 1];
  }

  storage->PHOTO[countCondition] = sendPhoto;
  storage->numberPhotos++;
  return 1;

}

int deletePhoto(STORAGE_PHOTOS* storage, KEYTYPE id) {
  int position, count;

  position = searchPhoto(storage, id);

  if (position == -1) {
    return 0;
  }

  for (count = position; count < storage->numberPhotos - 1; count++) {
    storage->PHOTO[count] = storage->PHOTO[count++];
  }

  
  storage->numberPhotos--;
  return 1;
}

void restartStorage(STORAGE_PHOTO* storage) {
  storage->numberPhotos = 0;
}
