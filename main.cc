#include <iostream>

#include "foodpantry.h"
#include "volunteer.h"

std::shared_ptr<FoodPantry> CreatePantry(const std::string &pantry_name) {
  return std::make_shared<FoodPantry>(pantry_name);
}

int main() {
  Volunteer jc("JC");
  Volunteer paul("Paul");

  std::shared_ptr<FoodPantry> tuffys_pantry = CreatePantry("Tuffy's Pantry");

  std::cout << tuffys_pantry.use_count() << std::endl;
  
  jc.AssignToPantry(tuffys_pantry);
  paul.AssignToPantry(tuffys_pantry);

  std::cout << tuffys_pantry.use_count() << std::endl;

  jc.AssignedPantry()->Donate("Mango", 5);
  paul.AssignedPantry()->Donate("Mango", 20);

  tuffys_pantry->DisplayPantryItems();

  std::shared_ptr<FoodPantry> ant_pantry = CreatePantry("Ant's Pantry");
  jc.AssignToPantry(ant_pantry);
  paul.AssignToPantry(ant_pantry);

  std::cout << tuffys_pantry.use_count() << std::endl;

  tuffys_pantry = nullptr;
  std::cout << tuffys_pantry.use_count() << std::endl;

  std::cout << "TUFFY121L" << std::endl;
  
  std::cout << "Lab partner 1 name: Phu LAm" << std::endl;
  std::cout << "Email: phuphulamb75@gmail.com" << std::endl;
  std::cout << "GitHub: PML75" << std::endl;
  std::cout << "Lab partner 2 name: Antonio Contreras" << std::endl;
  std::cout << "Email: antonio_c@csu.fullerton.edu" << std::endl;
  std::cout << "GitHub: Antonio-E-Contreras" << std::endl;
}
