# Python 3
# Problema UVa 11559, Event Planning

"""
Input:
    People, budget, hotels, weekends   # Con un try... except EOF
    Se leen el numero de hoteles
    Por cada leida se lee el numero de camas por habitacion

    Para que un hotel sea considerado, todas las semanas debe tener igual
    o mayor cantidad de camas que de integrantes

    El precio de precioSemana * nIntegrantes * semanas debe ser menor o igual al budget
"""

if __name__ == "__main__":
    keepOn = True
    while keepOn:
        try:
            minPrice = -1
            integrants, budget, hotels, weekends = input().split()
            integrants  = int(integrants)
            budget      = int(budget)
            hotels      = int(hotels)
            weekends    = int(weekends)

            while hotels:
                wPrice  = int(input())
                tPrice = wPrice * integrants
                uBudget = False
                if tPrice <= budget:
                    uBudget = True

                beds = False
                wBeds = input().split()
                for i in wBeds:
                    if integrants <= int(i):
                        beds = True

                hotels -= 1

                if uBudget and beds and (tPrice < minPrice or minPrice == -1):
                    minPrice = tPrice
            if minPrice == -1:
                print("stay home")
            else:
                print(minPrice)
        except:
            keepOn = False