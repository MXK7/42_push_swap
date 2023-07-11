-- Fonction pour effectuer l'opération "sa" : échanger les deux éléments supérieurs de la pile A
local function swapA(stackA)
	if #stackA >= 2 then
	  stackA[#stackA], stackA[#stackA - 1] = stackA[#stackA - 1], stackA[#stackA]
	end
  end
  
  -- Fonction pour effectuer l'opération "sb" : échanger les deux éléments supérieurs de la pile B
  local function swapB(stackB)
	if #stackB >= 2 then
	  stackB[#stackB], stackB[#stackB - 1] = stackB[#stackB - 1], stackB[#stackB]
	end
  end
  
  -- Fonction pour effectuer l'opération "pa" : déplacer l'élément supérieur de la pile B vers la pile A
  local function pushA(stackA, stackB)
	if #stackB >= 1 then
	  table.insert(stackA, stackB[#stackB])
	  table.remove(stackB)
	end
  end
  
  -- Fonction pour effectuer l'opération "pb" : déplacer l'élément supérieur de la pile A vers la pile B
  local function pushB(stackA, stackB)
	if #stackA >= 1 then
	  table.insert(stackB, stackA[#stackA])
	  table.remove(stackA)
	end
  end
  
  -- Afficher le contenu de la pile A
  local function printStackA(stackA)
	io.write("Contenu de la pile A : ")
	for i = #stackA, 1, -1 do
	  io.write(stackA[i] .. " ")
	end
	io.write("\n")
  end
  
  -- Afficher le contenu de la pile B
  local function printStackB(stackB)
	io.write("Contenu de la pile B : ")
	for i = #stackB, 1, -1 do
	  io.write(stackB[i] .. " ")
	end
	io.write("\n")
  end
  
  -- Algorithme Push Swap pour trier la pile A
  local function pushSwap(stackA, stackB)
	-- Implémentez ici l'algorithme Push Swap en utilisant les fonctions définies ci-dessus
  end
  
  -- Exemple d'utilisation
  local stackA = {4, 2, 1, 3}  -- Pile A initiale
  local stackB = {}            -- Pile B initiale
  
  pushSwap(stackA, stackB)     -- Appel de l'algorithme Push Swap
  
  printStackA(stackA)          -- Affiche le contenu de la pile A après le tri
  printStackB(stackB)          -- Affiche le contenu de la pile B après le tri