import java.util.Scanner;

public class Team {
    public String school;
    public String sport;
    public String mascot;
    public final static String MOTTO = "Sportsmanship!";

    public Team() {
        school = "";
        sport = "";
        mascot = "";
    }

    public Team(String school, String sport, String mascot) {
        this.school = school;
        this.sport = sport;
        this.mascot = mascot;
    }

    // get methods
    public String getSchool() {
        return this.school;
    }

    public String getSport() {
        return this.sport;
    }

    public String getMascot() {
        return this.mascot;
    }
    public Team setTeamData() {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter school name >> ");
        //this.school = input.nextLine();
        school = input.nextLine();
        System.out.print("Enter sport >> ");
        //this.sport = input.nextLine();
        sport = input.nextLine();
        System.out.print("Enter mascot >> ");
        //this.mascot = input.nextLine();
        mascot = input.nextLine();
        return this;
    }

    public static void main(String[] args) {

    }
}