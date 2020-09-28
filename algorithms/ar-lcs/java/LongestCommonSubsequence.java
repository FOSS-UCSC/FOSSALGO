import java.util.Scanner;

public class LongestCommonSubsequence {

    public static void main(String[] args) {
        LongestCommonSubsequence lcs = new LongestCommonSubsequence();
        System.out.print("String 1 : ");
        String text1 = lcs.getInput();
        System.out.print("String 2 : ");
        String text2 = lcs.getInput();
        lcs.lcsLength(text1.toCharArray(), text2.toCharArray());
    }

    // get user inputs
    public String getInput() {
        Scanner scanner = new Scanner(System.in);
        return scanner.nextLine();
    }

    // find the length of longest common subsequence
    public void lcsLength(char[] txt1, char[] txt2) {
        int max = 0;
        int[][] matrix = new int[txt1.length + 1][txt2.length + 1];

        for (int i = 0; i < matrix.length - 1; i++) {
            for (int j = 0; j < matrix[i].length - 1; j++) {
                if (txt1[i] == txt2[j]) {
                    matrix[i + 1][j + 1] = matrix[i][j] + 1;
                } else {
                    matrix[i + 1][j + 1] = Math.max(matrix[i + 1][j], matrix[i][j + 1]);
                }
                if (matrix[i + 1][j + 1] > max) {
                    max = matrix[i + 1][j + 1];
                }
            }
        }
        System.out.println("Length of LCS = " + max);
    }
}
