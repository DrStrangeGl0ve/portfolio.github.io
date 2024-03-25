using System.Collections;
using System.Collections.Generic;
using JetBrains.Annotations;
using UnityEngine;

public class YellowMinionAI : MonoBehaviour
{
    Rigidbody minionRb;
    UnityEngine.AI.NavMeshAgent minionAgent;
    public List<GameObject> purpleTurrets;
    public int turretIndex;
    // Start is called before the first frame update
    void Start()
    {
        minionAgent = GetComponent<UnityEngine.AI.NavMeshAgent>();

        //Puts target turrets into a list for targeting via index number.
        turretIndex = 0;
        purpleTurrets[0] = GameObject.Find("Purple Bot Tier 1");
        purpleTurrets[1] = GameObject.Find("Purple Bot Tier 2");
        purpleTurrets[2] = GameObject.Find("Purple Base");

        //Sends minions automatically to first enemy turret. Paths around obstacles and other RBs.
        minionAgent.destination = purpleTurrets[turretIndex].transform.position;

    }

    // Update is called once per frame
    void Update()
    {


    }
    void OnCollisionEnter(Collision collision)
    {
        if (collision.gameObject.name == "Purple Bot Tier 1")
        {
            turretIndex++;
            minionAgent.destination = purpleTurrets[turretIndex].transform.position;
            Destroy(collision.gameObject);
        }
        if (collision.gameObject.name == "Purple Bot Tier 2")
        {
            turretIndex++;
            minionAgent.destination = purpleTurrets[turretIndex].transform.position;
            Destroy(collision.gameObject);
        }
    }
}
