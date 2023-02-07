/** ******************************************************************
 TAD Árvore AVL
 Estrutura de Dados II

 GRUPO

 Nome: Gabriela Lopes Francisco
 TIA: 31744591

 Nome: Giulia Barbieri Quagliano
 TIA: 42013070

 Nome: Jenifer Mathias dos Santos
 TIA: 32092946

 Nome: Lucas Martins de Souza
 TIA: 31943187
****************************************************************** */

class Alimento {

public:
    string food_and_serving;
    int calories;
    int calories_from_fat;
    int total_fat_g;
    int total_fat_dv;
    int sodium_g;
    int sodium_dv;
    int potassium_g;
    int potassium_dv;
    int total_carbo_hydrate_g;
    int total_carbo_hydrate_dv;
    int dietary_fiber_g;
    int dietary_fiber_dv;
    int sugars_g;
    int protein_g;
    int vitamin_a_dv;
    int vitamin_c_dv;
    int calcium_dv;
    int iron_dv;
    int saturated_fat_dv;
    int saturated_fat_mg;
    int chole_sterol_dv;
    int chole_sterol_mg;
    string food_type;

    Alimento() {} //Default Constructor

    //constructor with parameters
    Alimento(
            string food_and_serving,
            int calories,
            int calories_from_fat,
            int total_fat_g,
            int total_fat_dv,
            int sodium_g,
            int sodium_dv,
            int potassium_g,
            int potassium_dv,
            int total_carbo_hydrate_g,
            int total_carbo_hydrate_dv,
            int dietary_fiber_g,
            int dietary_fiber_dv,
            int sugars_g,
            int protein_g,
            int vitamin_a_dv,
            int vitamin_c_dv,
            int calcium_dv,
            int iron_dv,
            int saturated_fat_dv,
            int saturated_fat_mg,
            int chole_sterol_dv,
            int chole_sterol_mg,
            string food_type) {

        this->food_and_serving = food_and_serving;
        this->calories = calories;
        this->calories_from_fat = calories_from_fat;
        this->total_fat_g = total_fat_g;
        this->total_fat_dv = total_fat_dv;
        this->total_fat_dv = total_fat_dv;
        this->sodium_g = sodium_g;
        this->sodium_dv = sodium_dv;
        this->potassium_g = potassium_g;
        this->potassium_dv = potassium_dv;
        this->total_carbo_hydrate_g = total_carbo_hydrate_g;
        this->total_carbo_hydrate_dv = total_carbo_hydrate_dv;
        this->dietary_fiber_g = dietary_fiber_g;
        this->dietary_fiber_dv = dietary_fiber_dv;
        this->sugars_g = sugars_g;
        this->protein_g = protein_g;
        this->vitamin_a_dv = vitamin_a_dv;
        this->vitamin_c_dv = vitamin_c_dv;
        this->calcium_dv = calcium_dv;
        this->iron_dv = iron_dv;
        this->saturated_fat_dv = saturated_fat_dv;
        this->saturated_fat_mg = saturated_fat_mg;
        this->chole_sterol_dv = chole_sterol_dv;
        this->chole_sterol_mg = chole_sterol_mg;
        this->food_type = food_type;
    }

};
