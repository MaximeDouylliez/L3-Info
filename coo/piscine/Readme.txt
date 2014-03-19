Tout compile mais à l'exécution on obtient une erreur de mémoire :

"Exception in thread "main" java.lang.OutOfMemoryError: Java heap space
	at java.util.Arrays.copyOf(Arrays.java:2760)
	at java.util.Arrays.copyOf(Arrays.java:2734)
	at java.util.ArrayList.ensureCapacity(ArrayList.java:167)
	at java.util.ArrayList.add(ArrayList.java:351)
	at action.Scheduler.contenuFaire(Scheduler.java:13)
	at action.Action.faire(Action.java:9)
	at action.Ordonnanceur.faire(Ordonnanceur.java:17)
	at piscine.Piscine.main(Piscine.java:26)"

Donc nous n'avons pas pu tester si le programme fonctionne.

