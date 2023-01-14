//=========================================================================
//       HTML PAGE  
//=========================================================================


const char webpage[] = 
R"=====(
<!DOCTYPE html>
<html>
<!------------------------------C S S--------------------------------->
<head>
    <style>
        button{
          padding: auto;
          height: 40px;
          width: 70%;
          margin-top: 50px;
          border-radius: 15px;
        }



        #rettangolo {
            display: inline-block;
            border-radius: 15px;
            background: #4f4e4e;
            border: 5px solid;
            margin: auto;
            width: 70%;
            padding-bottom: 20px;
            text-align: center;

        }


        #rettangolo2 {
          display: inline-block;
          padding-top: px;
          border-radius: 15px;
          background: #4f4e4e;
          border: 5px solid;
          margin: auto;
          margin-top: 50px;
          width: 70%;
          height: auto;
          text-align: center;
        }

        onni{
            filter: invert(0) drop-shadow(0 0 4px red) drop-shadow(0 0 15px red);
        }

        on{
            filter: invert(0) drop-shadow(0 0 3px orange);
        }

        div:active on{
            filter: invert(1);
        }
        div:hover on{
            filter: invert(1) invert(0) drop-shadow(0 0 3px orange);
        }

        .pulsante {
          transition: 0.6s;
          filter: invert(0);
          align-items: center;
          justify-content: center;
          padding-top: 4px;
          position: relative;

        }
    </style>

  <link rel="icon" type="image/x-icon" href="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAADwAAAA8CAYAAAA6/NlyAAAACXBIWXMAAAsTAAALEwEAmpwYAAADo0lEQVR4nO2a329MQRTHv6qqHvza/vCjJcGjtP8CbyyqES19IlpJN0QaSkVE4gElKP+C+PGM0DQSJE3QhheehAQpHlS1yvrR0q6c5Gxyc3K2vTsz9+5t3E8yyabd/c45d+aeOXNmgJiYmJiYGC/1AAYBfAKwFf8BHwFkuH3ADCYB4BCAYwAWT/G9jGi5WACgnRtpR4YiAHsBfPY4cd+Bw3c83yHtFu6roKwE8ERxYtyBw2nlu48ArECBWM/BJ6O06w4cvpJDm4LdOoTMbgB/FGO+A+gAUOzA4dmslc4xg3YhJHYC+KsYcRNAtY/f+3U4C2neVn5HNjQiYDbz05UdU2Se5VMjX4fB2scBTCgjnUSAAWpYdDjGiUQ+mDicZZvywL8EEciKADxQRrbJQMvGYWK7Ej96+Z13Rrti6AFDLVuHiYOKDiU9TljE08Yr3p3HOxuEw9T3LaEz7CojO6u8M+UWei4cJiqUgTgDSxYC+CFED1tqunKYOCK0aM2ebyPYIgQHAJRGyOF5AN4LvT02gr1C7ATscekwcVLoPTQVWgpg0iNEn1dF0OHVip2VJkL1wrA+uMG1w0S/0KwzEekUIhci7PAloXnKROSeENkRYYebhGaPicgLIVITYYdrheZz22JbBsDyCDtcJTRpqcqbX0LEdv0N0uFSofnTRGRMiJQ4Mu6tR/ONI825wtbfJiJDQsRVqTTJU47aRkea5cJWqnLmzWshshbRpUbY+spEpEeIULUhqjQIW++aiFwWIqcRXWSS1GVancx42mNEF5laGlUzK0VSPuGzDBs2VaJsPMnFASP6xJOjDXfUOKocxxizXykAuFqPXTAHwDthY8pGMKEcddBJYVRICdu+TXNU64uLQpQSkjIUnoRymEcFR2uW8SGZV/gqCs8NYdOoaaXDbyG+kFO7VbGnzXVweCY6oDOeDQifpHK+1D/NEa0RawB8FR2lQ3Y6qQTREUfFRZU65SBrPKTp3aqMLNmyKeiOm0UGlm3XArptU6YEqGxGRTcRQqE5x5WHQR4JF8lJCa+z3ttB3pENzdksW5R32puRdXCemy/VnC4O5NAeCWMaT1X1f5rDsOyGo49P9Rp4o57g0Svhz7X8v06OtvJag4zGgQUovxTzGjg6haG2Lc2j7nzpsWEJgPNKVmbTKDc+5zKDCgJK3vfxDT0tmk/XJnmLl3KxEQibCj6i6eJrEi958zHGbYj/1s2blEbL2wUxMTExMZjJ/AON6kIqrbzbKwAAAABJRU5ErkJggg==">

  <p>
    <meta name="viewport" content="width=device-width, initial-scale=1">
  </p>
  <title>HoltorfPURNA</title>
  
</head>
<!----------------------------H T M L--------------------------------->
<body style="margin-top: 70px; background-color:#202124; text-align:center;font-family:verdana">
    
      <div onClick="rel0_request(); getrel0();" id="rettangolo">
        <h2 style="color: #bcc0c3"> SWITCH SCRIVANIA  </h2>
        <onni id="switch_0">
          <img style="margin-top: 20px;" src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAADwAAAA8CAYAAAA6/NlyAAAACXBIWXMAAAsTAAALEwEAmpwYAAADo0lEQVR4nO2a329MQRTHv6qqHvza/vCjJcGjtP8CbyyqES19IlpJN0QaSkVE4gElKP+C+PGM0DQSJE3QhheehAQpHlS1yvrR0q6c5Gxyc3K2vTsz9+5t3E8yyabd/c45d+aeOXNmgJiYmJiYGC/1AAYBfAKwFf8BHwFkuH3ADCYB4BCAYwAWT/G9jGi5WACgnRtpR4YiAHsBfPY4cd+Bw3c83yHtFu6roKwE8ERxYtyBw2nlu48ArECBWM/BJ6O06w4cvpJDm4LdOoTMbgB/FGO+A+gAUOzA4dmslc4xg3YhJHYC+KsYcRNAtY/f+3U4C2neVn5HNjQiYDbz05UdU2Se5VMjX4fB2scBTCgjnUSAAWpYdDjGiUQ+mDicZZvywL8EEciKADxQRrbJQMvGYWK7Ej96+Z13Rrti6AFDLVuHiYOKDiU9TljE08Yr3p3HOxuEw9T3LaEz7CojO6u8M+UWei4cJiqUgTgDSxYC+CFED1tqunKYOCK0aM2ebyPYIgQHAJRGyOF5AN4LvT02gr1C7ATscekwcVLoPTQVWgpg0iNEn1dF0OHVip2VJkL1wrA+uMG1w0S/0KwzEekUIhci7PAloXnKROSeENkRYYebhGaPicgLIVITYYdrheZz22JbBsDyCDtcJTRpqcqbX0LEdv0N0uFSofnTRGRMiJQ4Mu6tR/ONI825wtbfJiJDQsRVqTTJU47aRkea5cJWqnLmzWshshbRpUbY+spEpEeIULUhqjQIW++aiFwWIqcRXWSS1GVancx42mNEF5laGlUzK0VSPuGzDBs2VaJsPMnFASP6xJOjDXfUOKocxxizXykAuFqPXTAHwDthY8pGMKEcddBJYVRICdu+TXNU64uLQpQSkjIUnoRymEcFR2uW8SGZV/gqCs8NYdOoaaXDbyG+kFO7VbGnzXVweCY6oDOeDQifpHK+1D/NEa0RawB8FR2lQ3Y6qQTREUfFRZU65SBrPKTp3aqMLNmyKeiOm0UGlm3XArptU6YEqGxGRTcRQqE5x5WHQR4JF8lJCa+z3ttB3pENzdksW5R32puRdXCemy/VnC4O5NAeCWMaT1X1f5rDsOyGo49P9Rp4o57g0Svhz7X8v06OtvJag4zGgQUovxTzGjg6haG2Lc2j7nzpsWEJgPNKVmbTKDc+5zKDCgJK3vfxDT0tmk/XJnmLl3KxEQibCj6i6eJrEi958zHGbYj/1s2blEbL2wUxMTExMZjJ/AON6kIqrbzbKwAAAABJRU5ErkJggg==" alt="" class="pulsante"/>
        </onni>
      </div>
    
    
      <div onClick="rel1_request()" id="rettangolo2">
        <h2 style="color: #bcc0c3"> SWITCH LUCI </h2>
        <on>
          <img style="margin-top: 20px;" src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAADwAAAA8CAYAAAA6/NlyAAAACXBIWXMAAAsTAAALEwEAmpwYAAADo0lEQVR4nO2a329MQRTHv6qqHvza/vCjJcGjtP8CbyyqES19IlpJN0QaSkVE4gElKP+C+PGM0DQSJE3QhheehAQpHlS1yvrR0q6c5Gxyc3K2vTsz9+5t3E8yyabd/c45d+aeOXNmgJiYmJiYGC/1AAYBfAKwFf8BHwFkuH3ADCYB4BCAYwAWT/G9jGi5WACgnRtpR4YiAHsBfPY4cd+Bw3c83yHtFu6roKwE8ERxYtyBw2nlu48ArECBWM/BJ6O06w4cvpJDm4LdOoTMbgB/FGO+A+gAUOzA4dmslc4xg3YhJHYC+KsYcRNAtY/f+3U4C2neVn5HNjQiYDbz05UdU2Se5VMjX4fB2scBTCgjnUSAAWpYdDjGiUQ+mDicZZvywL8EEciKADxQRrbJQMvGYWK7Ej96+Z13Rrti6AFDLVuHiYOKDiU9TljE08Yr3p3HOxuEw9T3LaEz7CojO6u8M+UWei4cJiqUgTgDSxYC+CFED1tqunKYOCK0aM2ebyPYIgQHAJRGyOF5AN4LvT02gr1C7ATscekwcVLoPTQVWgpg0iNEn1dF0OHVip2VJkL1wrA+uMG1w0S/0KwzEekUIhci7PAloXnKROSeENkRYYebhGaPicgLIVITYYdrheZz22JbBsDyCDtcJTRpqcqbX0LEdv0N0uFSofnTRGRMiJQ4Mu6tR/ONI825wtbfJiJDQsRVqTTJU47aRkea5cJWqnLmzWshshbRpUbY+spEpEeIULUhqjQIW++aiFwWIqcRXWSS1GVancx42mNEF5laGlUzK0VSPuGzDBs2VaJsPMnFASP6xJOjDXfUOKocxxizXykAuFqPXTAHwDthY8pGMKEcddBJYVRICdu+TXNU64uLQpQSkjIUnoRymEcFR2uW8SGZV/gqCs8NYdOoaaXDbyG+kFO7VbGnzXVweCY6oDOeDQifpHK+1D/NEa0RawB8FR2lQ3Y6qQTREUfFRZU65SBrPKTp3aqMLNmyKeiOm0UGlm3XArptU6YEqGxGRTcRQqE5x5WHQR4JF8lJCa+z3ttB3pENzdksW5R32puRdXCemy/VnC4O5NAeCWMaT1X1f5rDsOyGo49P9Rp4o57g0Svhz7X8v06OtvJag4zGgQUovxTzGjg6haG2Lc2j7nzpsWEJgPNKVmbTKDc+5zKDCgJK3vfxDT0tmk/XJnmLl3KxEQibCj6i6eJrEi958zHGbYj/1s2blEbL2wUxMTExMZjJ/AON6kIqrbzbKwAAAABJRU5ErkJggg==" alt="" class="pulsante"/>
        </on>
      </div>
   
    <form action="/update" method="GET">
      <button> AGGIORNA FIRMWARE </button>
    </form>
    <!--form action="/reboot" method="POST">-->
    <button style="margin-top: 30px" onclick="reboot_confirm()" id="reboot"> REBOOT ESP </button>
    
    <!--</form>-->
<!---------------------------JavaScript------------------------------->
  <script>
    //function displays text message
    var xhr = new XMLHttpRequest();

    window.onload = function() {
      getrel0();
    };


    async function getrel0() {    
      
        const response = await fetch('/getrel0');
        
        if (response.ok) {
          rel0_green();
        }
        else if (!response.ok) {
          rel0_red();
        }

        else{
          rel0_nostatus();
        }
      
        window.setInterval(getrel0(){}, 5000);
    }

    function rel0_red(){
      document.getElementById('switch_0').style.filter = "invert(0) drop-shadow(0 0 4px red) drop-shadow(0 0 15px red)";


    }
    

    function rel0_green(){
      document.getElementById('switch_0').style.filter = "invert(0) drop-shadow(0 0 4px green) drop-shadow(0 0 15px green) drop-shadow(0 0 10px rgb(20, 250, 20))";
    }

    function rel0_nostatus(){
      document.getElementById('switch_0').style.filter = "drop-shadow(0 0 4px orange)";
    }



    function reboot_confirm(){
      
      conferma = confirm("Sei sicuro di voler riavviare??");
      if (conferma) {
        alert("Riavviando.. attenndi");
        xhr.open('GET', '/reboot');
        xhr.send()
        //richiesta di rebbot a esp
      } else {
        alert("Abortoooo!");
      }
    }

    function rel0_request(){
      xhr.open('GET', '/rel0');
      xhr.send()
    }

    function rel1_request(){
      xhr.open('GET', '/rel1');
      xhr.send()
    }

 
  </script>
</body>
</html>
)=====";