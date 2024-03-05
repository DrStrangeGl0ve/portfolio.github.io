import java.util.Scanner;

public class Game {
    private Team team1;
    private Team team2;
    private String time;

    // Default constructor
    public Game() {
        this.team1 = new Team();
        this.team2 = new Team();
        this.time = "";
    }

    // Overloaded constructor
    public Game(Team team1, Team team2, String time) {
        this.team1 = team1;
        this.team2 = team2;
        this.time = time;
    }

    // Getter methods
    public Team getTeam1() {
        return this.team1;
    }

    public Team getTeam2() {
        return this.team2;
    }

    public String getTime() {
        return this.time;
    }

    public Game setGameData() {
        this.team1.setTeamData();
        this.team2.setTeamData();
        Scanner input = new Scanner(System.in);
        System.out.print("Enter game time >> ");
        this.time = input.nextLine();
        return this;
    }
}

