using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PurpleMinionManager : MonoBehaviour
{

    public GameObject purpleMinion;
    public List<GameObject> pMinionsInGame;
    public PurpleUnit purpleMinionInfo;


    public int purpleMinionNum = 0;

    // Start is called before the first frame update
    void Start()
    {

        SpawnPurpleMinion();
    }


    void SpawnPurpleMinion()
    {
        int purpleMinionSpawnIndex = 0;
        for (int i = 0; i < purpleMinionInfo.waveSize; i++)
        {
            GameObject currentPurpleMinion = Instantiate(purpleMinion, purpleMinionInfo.purpleMinionSpawnLocation[purpleMinionSpawnIndex], Quaternion.identity);
            currentPurpleMinion.name = purpleMinionInfo.purpleUnitName + purpleMinionNum;
            purpleMinionSpawnIndex = (purpleMinionSpawnIndex + 1) % purpleMinionInfo.purpleMinionSpawnLocation.Length;
            pMinionsInGame.Add(currentPurpleMinion);
            purpleMinionNum++;
        }
    }

    // Update is called once per frame
    void Update()
    {

    }
}
