import org.jetbrains.annotations.NotNull;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class PassportProcessingPart2 {
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

    private static final Set<String> VALID_EYE_COLORS = new HashSet<>(Set.of(
            "amb",
            "blu",
            "brn",
            "gry",
            "grn",
            "hzl",
            "oth"
    ));

    public static void main(String [] args) throws IOException {
        final BufferedReader reader = new BufferedReader(new FileReader(INPUT_FILE_NAME));

        int validPassports = 0;

        // Get a chunk of lines, parse them into a list of entries, then process them.
        List<String> chunkOfLines = new ArrayList<>();
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
        final Map<String, String> passportAttributes = new HashMap<>();

        for (final String attribute : attributes) {
            passportAttributes.put(attribute.split(":")[0], attribute.split(":")[1]);
        }

        final boolean hasRequiredAttributes = passportAttributes.keySet().containsAll(REQUIRED_ATTRIBUTES);
        if (!hasRequiredAttributes) {
            return false;
        }

        return validatePassportData(passportAttributes);
    }

    private static boolean validatePassportData(final Map<String, String> passportAttributes) {
        int birthYear;
        int issueYear;
        int expirationYear;

        final String hairColorRegexPattern = "#[0-9a-f]{6}";
        final Pattern hairColorPattern = Pattern.compile(hairColorRegexPattern);
        final Matcher hairColorMatcher = hairColorPattern.matcher(passportAttributes.get("hcl"));

        try {
            birthYear = Integer.parseInt(passportAttributes.get("byr"));
            issueYear = Integer.parseInt(passportAttributes.get("iyr"));
            expirationYear = Integer.parseInt(passportAttributes.get("eyr"));

            // Validate passport ID is a number.
            Integer.parseInt(passportAttributes.get("pid"));
        }
        catch (NumberFormatException ex) {
            return false;
        }

        final boolean birthYearIsValid = (birthYear <= 2002 && birthYear >= 1920);
        final boolean issueYearIsValid = (issueYear <= 2020 && issueYear >= 2010);
        final boolean expirationYearIsValid = (expirationYear <= 2030 && expirationYear >= 2020);
        final boolean heightIsValid = isHeightValid(passportAttributes.get("hgt"));
        final boolean hairColorIsValid = hairColorMatcher.matches();
        final boolean eyeColorIsValid = VALID_EYE_COLORS.contains(passportAttributes.get("ecl"));
        final boolean passportIdIsValid = (passportAttributes.get("pid").length() == 9);

        return (birthYearIsValid &&
                issueYearIsValid &&
                expirationYearIsValid &&
                heightIsValid &&
                hairColorIsValid &&
                eyeColorIsValid &&
                passportIdIsValid);
    }

    private static boolean isHeightValid(final String heightString) {
        if (heightString.contains("cm")) {
            try {
                int height = Integer.parseInt(heightString.split("cm")[0]);
                return (height <= 193 && height >= 150);
            }
            catch (NumberFormatException ex) {
                return false;
            }
        }

        if (heightString.contains("in")) {
            try {
                int height = Integer.parseInt(heightString.split("in")[0]);
                return (height <= 76 && height >= 59);
            }
            catch (NumberFormatException ex) {
                return false;
            }
        }

        return false;
    }
}
