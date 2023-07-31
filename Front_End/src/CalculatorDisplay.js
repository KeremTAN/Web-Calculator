import React from 'react';

function CalculatorDisplay(props) {
    return (
        <input
        value={props.text}
        readOnly={true} 
        className='calculator-display'/>
    );
}

export default CalculatorDisplay;