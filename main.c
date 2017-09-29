#include <stdio.h>
#include <string.h>

/*
 * Программа-пример No1 из главы 15
   Руководства по С для новичков, 3-е издание
   Файл Chapter15ex1.c
   Эта программа спрашивает пользователей, сколько
   фильмов они видели в этом году, а затем входит в цикл,
   спрашивая название каждого фильма и его оценку по
   шкале от 1 до 10. Программа запомнит самый любимый
   и наименее понравившийся фильм
*/
#define SIZE 100

int main ()
{
  int ctr, numMovies, rating, favRating, leastRating;
  char moviName[SIZE], favourite[SIZE], least[SIZE];

  /*
    инициализировать favRating значением 0,
    т.о. любой фильм
    с рейтингом 1 или выше заменит
    это значение
    и leastRating
    значением 10, т.о. любой фильм
    с рейтингом 9 и ниже
    заменит его
    */
  favRating = 0;
  leastRating = 10;

  /* Выяснить, сколько фильмов посмотрел и может оценить пользователь
     Цикл будет выполняться, пока пользователь не введет значение больше 0 */

  do
    {
      printf("Сколько фильмов вы посмотрели за этот год?\n");
      scanf(" %i", &numMovies);

      if(numMovies < 1)
        {
          printf("Ни одного фильма! Как вы можете их оценивать?\n"
                     "Попробуйте снова!\n\n");
        }
      
    }while(getchar()!= '\n' || numMovies < 1);

  for(ctr = 1; ctr <= numMovies; ctr++)
    {
      printf("Введите название фильма:\n");
      fgets(moviName, SIZE, stdin);

      do {
          printf("Как бы вы его оценили по шкале от 1 до 10\n");
          scanf(" %i", &rating);
        }while(getchar()!= '\n' || rating < 1);

      //Проверить, не имеет ли данный фильм наивысший рейтинг
      if(rating > favRating)
        {
          strcpy (favourite, moviName);
          favRating = rating;
        }

      //Проверить, не имеет ли данный фильм низший рейтинг
      if(rating < leastRating)
        {
          strcpy (least, moviName);
          leastRating = rating;
        }
    }

  if(numMovies == 1 && favRating) { printf("\nВаш любимый фильм: %s", favourite); }
  else if(numMovies == 1 && leastRating) { printf("\nВаш наименее любимый фильм: %s", least); }
  else
    {
      printf("\nВаш любимый фильм: %s", favourite);
      printf("\nВаш наименее любимый фильм: %s", least);
    }

  printf("\n");
  return 0;
}