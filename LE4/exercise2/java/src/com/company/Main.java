package com.company;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.Random;

public class Main {

    public static ArrayList<String> generateStrings(int nrOfWords){
        //generate Random ArrayList
        String alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        Random random = new Random();
        int length = 1;

        StringBuilder sb = new StringBuilder();
        ArrayList<String> randStrings = new ArrayList<String>();
        for (int n=0; n < nrOfWords; n++){
            sb.setLength(0);
            for(int i = 0; i < length; i++) {

                // generate random index number
                int index = random.nextInt(alphabet.length());

                // get character specified by index
                // from the string
                char randomChar = alphabet.charAt(index);

                // append the character to string builder
                sb.append(randomChar);
            }
            String randomString = sb.toString();
            randStrings.add(randomString);
        }
        return randStrings;

    }
    public static void main(String[] args) {
        //generate random String ArrayList of size n
        int n = 10000000;
        ArrayList<String> randStrings = generateStrings(n);
        String randWord = randStrings.remove(0);

        // to show that it works
        randStrings.add(randWord);

        Iterator<String> it = randStrings.iterator();
        ElementMatcher<String> matcher = new ElementMatcher<String>(randWord);

        long start =System.nanoTime();
        Iterator<String> found = Finder.findIfMatcher(it, matcher);
        long finish =System.nanoTime();
        long timeElapsed = finish - start;
        System.out.println("element matches:" );
        System.out.println(found != null);
        System.out.format("milliseconds elapsed: %d%n",timeElapsed/1000000);

        System.out.format("for String ArrayList of size: %d ", n);
    }
}
