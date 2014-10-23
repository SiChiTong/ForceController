#include "include/defs/defs.h"
#include "include/board/boardDynamixel.h"
#include "include/kinematic/kinematicLie.h"
#include "include/legModel/insectLeg.h"
#include "include/robotModel/robotMessor2.h"
#include "include/visualization/visualizerGL.h"
#include <iostream>
#include <stdio.h>


/*
 Paulina Jankowska


 */

using namespace std;

/** Klasa pokazowa dla dokumentacji doxygen
 *
 * Klasa pokazowa stworzona w celu zademonstrowania dzia�ania dokumentacji w kodzie. Nie jest ona przeznaczona do u�ycia.
 *
 * @authors Paulina Jankowska, Tomasz Chro�niak
 */
class DoxygenTestClass
{

private:
  /** Prywatny atrybut.
   *
   * Elementy prywatne nie s� wy�wietlane w generowanej dokumentacji.
   */
  int member1;

  /** Prywatna metoda.
   *
   * Zgodnie ze stwierdzeniem przy prywatnym atrybucie, elementy prywatne nie s� zawarte w dokumentacji.
   *
   * @param param1 parametr
   * @see member2
   */
  void privateMethod1(int param1);

protected:
  char member2; /**< Atrybut chroniony z dokumentacj� w tej samej linii (inline). W przypadku tego rodzaju dokumentacji wszystko co znajduje si� przed pierwsz� kropk� jest traktowane jako opis skr�cony. Ca�a reszta jest traktowana jako opis szczeg�owy. Mo�na tu u�ywa� link�w, np: {@link publicMember1}.  */

public:
  /** Atrybut publiczny z dokumentacj� w stylu pe�nym.
   *
   * Podobnie jak w przypadku dokumentacji inline, wszystko po pierwszej kropce jest traktowane jako opis szczeg�owy.
   * Do opisu szczeg�owego mo�na np. wkleja� fragmenty kodu, jak poni�ej:
   *
   *     metoda2(param1,param2);
   *
   * Taki fragment musi by� poprzedzony czterema spacjami. Zostanie on oznaczony na stronie w odpowiedni spos�b.
   * W dowolnym momencie mo�emy odwo�a� si� do jakiego�
   */
  int publicMember1;

  /** Tutaj znajduje si� przyk�ad publicznej metody.
   *
   * Dost�pne s� takie polecenia jak param, return. Pozwalaj� one na dodanie opisu do parametr�w oraz opisanie warto�ci zwracanych przez dan� metod�.
   * Do tego dost�pne jest tak�e polecenie throw (lub throws), kt�re pozwala okre�li� rodzaj wyj�tku, kt�ry mo�e wyst�pi�.
   *
   * @param parametr1 Parametry mog� zosta� opisane przy u�yciu komendy param. Nieopisane parametry nie wy�wietl� si� na li�cie parametr�w. Dodatkowo doxygen ostrze�e nas, �e jeden z parametr�w nie posiada w�asnej dokumentacji.
   * @throws NullPointerException Opis wyj�tku sk�ada si� z nazwy wyj�tku oraz opisu.
   * @throws IOException
   * @return Tutaj mo�na umie�ci� opis warto�ci zwracanej.
   * @see Tutaj mo�na umie�ci� linki do innych zdefiniowanych element�w.
   */
    virtual int metoda1(int parametr1, double parametr2);

    /** Tutaj znajduje si� opis kolejnej metody.
     *
     * @see publicMember1
     */
    int metoda2(int parametr1/**< [in] opis parametru wej�ciowego mo�na tak�e umie�ci� w linii, za parametrem. Dodatkowo mo�na u�y� opcjonalnego okre�lenia kierunku przep�ywu danych dla danego parametru. */, double parametr2/**< [out] opis parametru wyj�ciowego umieszczony w linii */)
    {
      publicMember1 = parametr1;
      return metoda1(parametr1,parametr2);
    }

    DoxygenTestClass();
    virtual ~DoxygenTestClass();

};

int main( int argc, const char** argv )
{
    try {
         Board* board;
         board = createBoardDynamixel();
         std::cout << "Board type: " << board->getName() << "\n";

         Kinematic* kinematicModel;
         kinematicModel = createKinematicLie("../resources/legModel.xml");
         std::cout << "Kinematic type: " << kinematicModel->getName() << "\n";
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what() << std::endl;
        return 1;
    }
    return 0;
}
