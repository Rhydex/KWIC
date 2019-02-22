class Alphabetizer extends React.Component {
    constructor(props) {
        super(props);
        this.state= {
            shift: this.props.shift || [],
            alph: []
        }
    }
    render() {
        return(
            <div>
                <OutputField alph={this.props.shift} />
            </div>
            
        )
    }
}