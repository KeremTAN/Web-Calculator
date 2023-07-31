import React from 'react'

function CalculatorButton(props) {
    return (
        <input type='button'
        value={props.caption}
        className={props.caption==="=" ? "calculator-equal-button" : null}/>
    );
}

export default CalculatorButton;
