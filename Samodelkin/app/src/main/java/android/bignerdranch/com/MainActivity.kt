package android.bignerdranch.com

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.provider.Contacts
import android.widget.Button
import android.widget.TextView
import kotlinx.android.synthetic.main.activity_main.*
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.launch

class MainActivity : AppCompatActivity() {
    private var characterData = CharacterGenerator.generate()
    private val CHARACTER_DATA_KEY = "CHARACTER_DATA_KEY"
    private var Bundle.characterData
        get() = getSerializable(CHARACTER_DATA_KEY) as CharacterGenerator.CharacterData
        set(value) = putSerializable(CHARACTER_DATA_KEY, value)
    override fun onSaveInstanceState(outState: Bundle){
        super.onSaveInstanceState(outState)
//        outState.putSerializable(CHARACTER_DATA_KEY, characterData)
        outState.characterData = characterData
    }


    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
//        val nameTextView = findViewById<TextView>(R.id.nameTextView)
//        val raceTextView = findViewById<TextView>(R.id.raceTextView)
//        val dexterityTextView = findViewById<TextView>(R.id.dexterityTextView)
//        val wisdomTextView = findViewById<TextView>(R.id.wisdomTextView)
//        val strengthTextView = findViewById<TextView>(R.id.strengthTextView)
//        val generateButton = findViewById<Button>(R.id.generateButton)
//        displayCharacterData()
//        characterData = savedInstanceState?.let{
//            it.getSerializable(CHARACTER_DATA_KEY) as CharacterGenerator.CharacterData
//        }?:CharacterGenerator.generate()
        characterData = savedInstanceState?.characterData?:CharacterGenerator.generate()
        generateButton.setOnClickListener{
            characterData = CharacterGenerator.generate()
            displayCharacterData()
//            charcterData.run{
//                nameTextView.text = this.name
//                raceTextView.text = race
//                dexterityTextView.text = dex
//                wisdomTextView.text = wis
//                strengthTextView.text = str
//            }

        }
//        generateButton.setOnClickListener{
////            characterData = CharacterGenerator.fromApiData("halfing,Lars Kizzy, 14, 13, 8")
//            characterData = fetchCharacterData()
//            displayCharacterData()
//        }
//        generateButton.setOnClickListener{
//            launch(Contacts.Intents.UI){
//                characterData = fetchCharacterData().await()
//                displayCharacterData()
//            }
//        }
        displayCharacterData()
    }
    private fun displayCharacterData(){
        characterData.run{
            nameTextView.text = this.name
            raceTextView.text = race
            dexterityTextView.text = dex
            wisdomTextView.text = wis
            strengthTextView.text = str
        }
    }
}
//文件传输
//调试
//设备   每次选择
//鐢变簬鐩爣璁＄畻鏈虹Н鏋佹嫆缁濓紝鏃犳硶杩炴帴銆?(10061)
