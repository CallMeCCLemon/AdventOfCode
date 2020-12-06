import org.jetbrains.annotations.NotNull;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class PassportProcessing {
    private static final String INPUT_FILE_NAME = "Day4/input.txt";
    private static final Set<String> REQUIRED_ATTRIBUTES = new HashSet<>(Set.of(
            "byr",
            "iyr",
            "eyr",
            "hgt",
            "hcl",
            "ecl",
            "pid"
    ));

    public static void main(String [] args) throws IOException {
        final BufferedReader reader = new BufferedReader(new FileReader(INPUT_FILE_NAME));

        int validPassports = 0;

        // Get a chunk of lines, parse them into a list of entries, then process them.
        final List<String> chunkOfLines = new ArrayList<>();
        String line = reader.readLine();
        while (line != null) {
            if (line.equals("")) {
                if (passportIsValid(chunkOfLines)) {
                    validPassports++;
                }

                chunkOfLines.clear();

            } else {
                chunkOfLines.addAll(Arrays.asList(line.split(" ")));
            }
            line = reader.readLine();
        }

        if (!chunkOfLines.isEmpty()) {
            if (passportIsValid(chunkOfLines)) {
                validPassports++;
            }
        }
        reader.close();

        System.out.println("Number of valid passports: " + validPassports);
    }

    private static boolean passportIsValid(final @NotNull List<String> attributes) {
        final Set<String> attributeKeys = new HashSet<>();

        for (final String attribute : attributes) {
            attributeKeys.add(attribute.split(":")[0]);
        }

        return attributeKeys.containsAll(REQUIRED_ATTRIBUTES);
    }
}
