// Generated from /home/jona/myGit/gen_code_for_audit/syntax/g4tool/AuditGenParser.g4 by ANTLR 4.8
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class AuditGenParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.8", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		GEN_LEXER=1, GEN_GRAMMAR=2, GEN_PARSER=3, GEN_EOF=4, GEN_OPTIONS=5, GEN_IMPORT=6, 
		COMMA=7, COLON=8, COLON_COLON=9, STAR=10, PLUS=11, QUESTION=12, LPAREN=13, 
		RPAREN=14, AT_SIGN=15, DOT=16, BAR=17, SEMICOLON=18, EQUAL=19, LBRACE=20, 
		RBRACE=21, POUND=22, IDENTIFIER=23, UNSIGNED_INTEGER=24, DQUOTA_STRING=25, 
		SQUOTA_STRING=26, WHITESPACE=27, BLOCK_COMMENT=28, LINE_COMMENT=29;
	public static final int
		RULE_multi_stmts = 0, RULE_stmt = 1, RULE_header_stmt = 2, RULE_parser_lexer_name = 3, 
		RULE_import_stmt = 4, RULE_identifier = 5, RULE_cfg_rule_stmt = 6, RULE_rule_name = 7, 
		RULE_label_name = 8, RULE_cfg_rule = 9, RULE_alternative = 10, RULE_rule_component = 11, 
		RULE_closure_sign = 12, RULE_label_def = 13, RULE_label_element = 14, 
		RULE_atom = 15, RULE_block = 16;
	private static String[] makeRuleNames() {
		return new String[] {
			"multi_stmts", "stmt", "header_stmt", "parser_lexer_name", "import_stmt", 
			"identifier", "cfg_rule_stmt", "rule_name", "label_name", "cfg_rule", 
			"alternative", "rule_component", "closure_sign", "label_def", "label_element", 
			"atom", "block"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'lexer'", "'grammar'", "'parser'", "'EOF'", "'options'", "'import'", 
			"','", "':'", "'::'", "'*'", "'+'", "'?'", "'('", "')'", "'@'", "'.'", 
			"'|'", "';'", "'='", "'{'", "'}'", "'#'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "GEN_LEXER", "GEN_GRAMMAR", "GEN_PARSER", "GEN_EOF", "GEN_OPTIONS", 
			"GEN_IMPORT", "COMMA", "COLON", "COLON_COLON", "STAR", "PLUS", "QUESTION", 
			"LPAREN", "RPAREN", "AT_SIGN", "DOT", "BAR", "SEMICOLON", "EQUAL", "LBRACE", 
			"RBRACE", "POUND", "IDENTIFIER", "UNSIGNED_INTEGER", "DQUOTA_STRING", 
			"SQUOTA_STRING", "WHITESPACE", "BLOCK_COMMENT", "LINE_COMMENT"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "AuditGenParser.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public AuditGenParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class Multi_stmtsContext extends ParserRuleContext {
		public TerminalNode EOF() { return getToken(AuditGenParser.EOF, 0); }
		public List<StmtContext> stmt() {
			return getRuleContexts(StmtContext.class);
		}
		public StmtContext stmt(int i) {
			return getRuleContext(StmtContext.class,i);
		}
		public Multi_stmtsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_multi_stmts; }
	}

	public final Multi_stmtsContext multi_stmts() throws RecognitionException {
		Multi_stmtsContext _localctx = new Multi_stmtsContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_multi_stmts);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(35); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(34);
				stmt();
				}
				}
				setState(37); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( (((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << GEN_LEXER) | (1L << GEN_GRAMMAR) | (1L << GEN_PARSER) | (1L << GEN_IMPORT) | (1L << IDENTIFIER) | (1L << DQUOTA_STRING) | (1L << SQUOTA_STRING))) != 0) );
			setState(39);
			match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StmtContext extends ParserRuleContext {
		public Header_stmtContext header_stmt() {
			return getRuleContext(Header_stmtContext.class,0);
		}
		public Import_stmtContext import_stmt() {
			return getRuleContext(Import_stmtContext.class,0);
		}
		public Cfg_rule_stmtContext cfg_rule_stmt() {
			return getRuleContext(Cfg_rule_stmtContext.class,0);
		}
		public StmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_stmt; }
	}

	public final StmtContext stmt() throws RecognitionException {
		StmtContext _localctx = new StmtContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_stmt);
		try {
			setState(44);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case GEN_LEXER:
			case GEN_GRAMMAR:
			case GEN_PARSER:
				enterOuterAlt(_localctx, 1);
				{
				setState(41);
				header_stmt();
				}
				break;
			case GEN_IMPORT:
				enterOuterAlt(_localctx, 2);
				{
				setState(42);
				import_stmt();
				}
				break;
			case IDENTIFIER:
			case DQUOTA_STRING:
			case SQUOTA_STRING:
				enterOuterAlt(_localctx, 3);
				{
				setState(43);
				cfg_rule_stmt();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Header_stmtContext extends ParserRuleContext {
		public TerminalNode GEN_GRAMMAR() { return getToken(AuditGenParser.GEN_GRAMMAR, 0); }
		public Parser_lexer_nameContext parser_lexer_name() {
			return getRuleContext(Parser_lexer_nameContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(AuditGenParser.SEMICOLON, 0); }
		public TerminalNode GEN_PARSER() { return getToken(AuditGenParser.GEN_PARSER, 0); }
		public TerminalNode GEN_LEXER() { return getToken(AuditGenParser.GEN_LEXER, 0); }
		public Header_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_header_stmt; }
	}

	public final Header_stmtContext header_stmt() throws RecognitionException {
		Header_stmtContext _localctx = new Header_stmtContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_header_stmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(47);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==GEN_LEXER || _la==GEN_PARSER) {
				{
				setState(46);
				_la = _input.LA(1);
				if ( !(_la==GEN_LEXER || _la==GEN_PARSER) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				}
			}

			setState(49);
			match(GEN_GRAMMAR);
			setState(50);
			parser_lexer_name();
			setState(51);
			match(SEMICOLON);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Parser_lexer_nameContext extends ParserRuleContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public Parser_lexer_nameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parser_lexer_name; }
	}

	public final Parser_lexer_nameContext parser_lexer_name() throws RecognitionException {
		Parser_lexer_nameContext _localctx = new Parser_lexer_nameContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_parser_lexer_name);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(53);
			identifier();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Import_stmtContext extends ParserRuleContext {
		public TerminalNode GEN_IMPORT() { return getToken(AuditGenParser.GEN_IMPORT, 0); }
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(AuditGenParser.SEMICOLON, 0); }
		public Import_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_import_stmt; }
	}

	public final Import_stmtContext import_stmt() throws RecognitionException {
		Import_stmtContext _localctx = new Import_stmtContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_import_stmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(55);
			match(GEN_IMPORT);
			setState(56);
			identifier();
			setState(57);
			match(SEMICOLON);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IdentifierContext extends ParserRuleContext {
		public TerminalNode IDENTIFIER() { return getToken(AuditGenParser.IDENTIFIER, 0); }
		public TerminalNode SQUOTA_STRING() { return getToken(AuditGenParser.SQUOTA_STRING, 0); }
		public TerminalNode DQUOTA_STRING() { return getToken(AuditGenParser.DQUOTA_STRING, 0); }
		public IdentifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_identifier; }
	}

	public final IdentifierContext identifier() throws RecognitionException {
		IdentifierContext _localctx = new IdentifierContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_identifier);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(59);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << IDENTIFIER) | (1L << DQUOTA_STRING) | (1L << SQUOTA_STRING))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Cfg_rule_stmtContext extends ParserRuleContext {
		public Rule_nameContext rule_name() {
			return getRuleContext(Rule_nameContext.class,0);
		}
		public TerminalNode COLON() { return getToken(AuditGenParser.COLON, 0); }
		public List<Cfg_ruleContext> cfg_rule() {
			return getRuleContexts(Cfg_ruleContext.class);
		}
		public Cfg_ruleContext cfg_rule(int i) {
			return getRuleContext(Cfg_ruleContext.class,i);
		}
		public TerminalNode SEMICOLON() { return getToken(AuditGenParser.SEMICOLON, 0); }
		public List<TerminalNode> BAR() { return getTokens(AuditGenParser.BAR); }
		public TerminalNode BAR(int i) {
			return getToken(AuditGenParser.BAR, i);
		}
		public TerminalNode GEN_EOF() { return getToken(AuditGenParser.GEN_EOF, 0); }
		public Cfg_rule_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_cfg_rule_stmt; }
	}

	public final Cfg_rule_stmtContext cfg_rule_stmt() throws RecognitionException {
		Cfg_rule_stmtContext _localctx = new Cfg_rule_stmtContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_cfg_rule_stmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(61);
			rule_name();
			setState(62);
			match(COLON);
			setState(63);
			cfg_rule();
			setState(68);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==BAR) {
				{
				{
				setState(64);
				match(BAR);
				setState(65);
				cfg_rule();
				}
				}
				setState(70);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(72);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==GEN_EOF) {
				{
				setState(71);
				match(GEN_EOF);
				}
			}

			setState(74);
			match(SEMICOLON);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Rule_nameContext extends ParserRuleContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public Rule_nameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_rule_name; }
	}

	public final Rule_nameContext rule_name() throws RecognitionException {
		Rule_nameContext _localctx = new Rule_nameContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_rule_name);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(76);
			identifier();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Label_nameContext extends ParserRuleContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public Label_nameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_label_name; }
	}

	public final Label_nameContext label_name() throws RecognitionException {
		Label_nameContext _localctx = new Label_nameContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_label_name);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(78);
			identifier();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Cfg_ruleContext extends ParserRuleContext {
		public AlternativeContext alternative() {
			return getRuleContext(AlternativeContext.class,0);
		}
		public Label_defContext label_def() {
			return getRuleContext(Label_defContext.class,0);
		}
		public Cfg_ruleContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_cfg_rule; }
	}

	public final Cfg_ruleContext cfg_rule() throws RecognitionException {
		Cfg_ruleContext _localctx = new Cfg_ruleContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_cfg_rule);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(80);
			alternative();
			setState(82);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==POUND) {
				{
				setState(81);
				label_def();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class AlternativeContext extends ParserRuleContext {
		public List<Rule_componentContext> rule_component() {
			return getRuleContexts(Rule_componentContext.class);
		}
		public Rule_componentContext rule_component(int i) {
			return getRuleContext(Rule_componentContext.class,i);
		}
		public AlternativeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_alternative; }
	}

	public final AlternativeContext alternative() throws RecognitionException {
		AlternativeContext _localctx = new AlternativeContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_alternative);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(85); 
			_errHandler.sync(this);
			_alt = 1;
			do {
				switch (_alt) {
				case 1:
					{
					{
					setState(84);
					rule_component();
					}
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(87); 
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,6,_ctx);
			} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Rule_componentContext extends ParserRuleContext {
		public Label_elementContext label_element() {
			return getRuleContext(Label_elementContext.class,0);
		}
		public Closure_signContext closure_sign() {
			return getRuleContext(Closure_signContext.class,0);
		}
		public AtomContext atom() {
			return getRuleContext(AtomContext.class,0);
		}
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public TerminalNode GEN_EOF() { return getToken(AuditGenParser.GEN_EOF, 0); }
		public TerminalNode SEMICOLON() { return getToken(AuditGenParser.SEMICOLON, 0); }
		public Rule_componentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_rule_component; }
	}

	public final Rule_componentContext rule_component() throws RecognitionException {
		Rule_componentContext _localctx = new Rule_componentContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_rule_component);
		int _la;
		try {
			setState(103);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,10,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(89);
				label_element();
				setState(91);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << STAR) | (1L << PLUS) | (1L << QUESTION))) != 0)) {
					{
					setState(90);
					closure_sign();
					}
				}

				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(93);
				atom();
				setState(95);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << STAR) | (1L << PLUS) | (1L << QUESTION))) != 0)) {
					{
					setState(94);
					closure_sign();
					}
				}

				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(97);
				block();
				setState(99);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << STAR) | (1L << PLUS) | (1L << QUESTION))) != 0)) {
					{
					setState(98);
					closure_sign();
					}
				}

				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(101);
				match(GEN_EOF);
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(102);
				match(SEMICOLON);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Closure_signContext extends ParserRuleContext {
		public TerminalNode STAR() { return getToken(AuditGenParser.STAR, 0); }
		public TerminalNode PLUS() { return getToken(AuditGenParser.PLUS, 0); }
		public List<TerminalNode> QUESTION() { return getTokens(AuditGenParser.QUESTION); }
		public TerminalNode QUESTION(int i) {
			return getToken(AuditGenParser.QUESTION, i);
		}
		public Closure_signContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_closure_sign; }
	}

	public final Closure_signContext closure_sign() throws RecognitionException {
		Closure_signContext _localctx = new Closure_signContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_closure_sign);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(105);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << STAR) | (1L << PLUS) | (1L << QUESTION))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			setState(107);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==QUESTION) {
				{
				setState(106);
				match(QUESTION);
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Label_defContext extends ParserRuleContext {
		public TerminalNode POUND() { return getToken(AuditGenParser.POUND, 0); }
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public Label_defContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_label_def; }
	}

	public final Label_defContext label_def() throws RecognitionException {
		Label_defContext _localctx = new Label_defContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_label_def);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(109);
			match(POUND);
			setState(110);
			identifier();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Label_elementContext extends ParserRuleContext {
		public Label_nameContext label_name() {
			return getRuleContext(Label_nameContext.class,0);
		}
		public TerminalNode EQUAL() { return getToken(AuditGenParser.EQUAL, 0); }
		public AtomContext atom() {
			return getRuleContext(AtomContext.class,0);
		}
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public Label_elementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_label_element; }
	}

	public final Label_elementContext label_element() throws RecognitionException {
		Label_elementContext _localctx = new Label_elementContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_label_element);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(112);
			label_name();
			setState(113);
			match(EQUAL);
			setState(116);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case IDENTIFIER:
			case DQUOTA_STRING:
			case SQUOTA_STRING:
				{
				setState(114);
				atom();
				}
				break;
			case LPAREN:
				{
				setState(115);
				block();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class AtomContext extends ParserRuleContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public AtomContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_atom; }
	}

	public final AtomContext atom() throws RecognitionException {
		AtomContext _localctx = new AtomContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_atom);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(118);
			identifier();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class BlockContext extends ParserRuleContext {
		public TerminalNode LPAREN() { return getToken(AuditGenParser.LPAREN, 0); }
		public List<AlternativeContext> alternative() {
			return getRuleContexts(AlternativeContext.class);
		}
		public AlternativeContext alternative(int i) {
			return getRuleContext(AlternativeContext.class,i);
		}
		public TerminalNode RPAREN() { return getToken(AuditGenParser.RPAREN, 0); }
		public List<TerminalNode> BAR() { return getTokens(AuditGenParser.BAR); }
		public TerminalNode BAR(int i) {
			return getToken(AuditGenParser.BAR, i);
		}
		public BlockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_block; }
	}

	public final BlockContext block() throws RecognitionException {
		BlockContext _localctx = new BlockContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_block);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(120);
			match(LPAREN);
			setState(121);
			alternative();
			setState(126);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==BAR) {
				{
				{
				setState(122);
				match(BAR);
				setState(123);
				alternative();
				}
				}
				setState(128);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(129);
			match(RPAREN);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\37\u0086\4\2\t\2"+
		"\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\3\2\6\2&\n\2\r\2\16\2\'\3\2\3\2\3\3\3\3\3\3\5\3/\n\3\3\4\5\4\62\n\4\3"+
		"\4\3\4\3\4\3\4\3\5\3\5\3\6\3\6\3\6\3\6\3\7\3\7\3\b\3\b\3\b\3\b\3\b\7\b"+
		"E\n\b\f\b\16\bH\13\b\3\b\5\bK\n\b\3\b\3\b\3\t\3\t\3\n\3\n\3\13\3\13\5"+
		"\13U\n\13\3\f\6\fX\n\f\r\f\16\fY\3\r\3\r\5\r^\n\r\3\r\3\r\5\rb\n\r\3\r"+
		"\3\r\5\rf\n\r\3\r\3\r\5\rj\n\r\3\16\3\16\5\16n\n\16\3\17\3\17\3\17\3\20"+
		"\3\20\3\20\3\20\5\20w\n\20\3\21\3\21\3\22\3\22\3\22\3\22\7\22\177\n\22"+
		"\f\22\16\22\u0082\13\22\3\22\3\22\3\22\2\2\23\2\4\6\b\n\f\16\20\22\24"+
		"\26\30\32\34\36 \"\2\5\4\2\3\3\5\5\4\2\31\31\33\34\3\2\f\16\2\u0086\2"+
		"%\3\2\2\2\4.\3\2\2\2\6\61\3\2\2\2\b\67\3\2\2\2\n9\3\2\2\2\f=\3\2\2\2\16"+
		"?\3\2\2\2\20N\3\2\2\2\22P\3\2\2\2\24R\3\2\2\2\26W\3\2\2\2\30i\3\2\2\2"+
		"\32k\3\2\2\2\34o\3\2\2\2\36r\3\2\2\2 x\3\2\2\2\"z\3\2\2\2$&\5\4\3\2%$"+
		"\3\2\2\2&\'\3\2\2\2\'%\3\2\2\2\'(\3\2\2\2()\3\2\2\2)*\7\2\2\3*\3\3\2\2"+
		"\2+/\5\6\4\2,/\5\n\6\2-/\5\16\b\2.+\3\2\2\2.,\3\2\2\2.-\3\2\2\2/\5\3\2"+
		"\2\2\60\62\t\2\2\2\61\60\3\2\2\2\61\62\3\2\2\2\62\63\3\2\2\2\63\64\7\4"+
		"\2\2\64\65\5\b\5\2\65\66\7\24\2\2\66\7\3\2\2\2\678\5\f\7\28\t\3\2\2\2"+
		"9:\7\b\2\2:;\5\f\7\2;<\7\24\2\2<\13\3\2\2\2=>\t\3\2\2>\r\3\2\2\2?@\5\20"+
		"\t\2@A\7\n\2\2AF\5\24\13\2BC\7\23\2\2CE\5\24\13\2DB\3\2\2\2EH\3\2\2\2"+
		"FD\3\2\2\2FG\3\2\2\2GJ\3\2\2\2HF\3\2\2\2IK\7\6\2\2JI\3\2\2\2JK\3\2\2\2"+
		"KL\3\2\2\2LM\7\24\2\2M\17\3\2\2\2NO\5\f\7\2O\21\3\2\2\2PQ\5\f\7\2Q\23"+
		"\3\2\2\2RT\5\26\f\2SU\5\34\17\2TS\3\2\2\2TU\3\2\2\2U\25\3\2\2\2VX\5\30"+
		"\r\2WV\3\2\2\2XY\3\2\2\2YW\3\2\2\2YZ\3\2\2\2Z\27\3\2\2\2[]\5\36\20\2\\"+
		"^\5\32\16\2]\\\3\2\2\2]^\3\2\2\2^j\3\2\2\2_a\5 \21\2`b\5\32\16\2a`\3\2"+
		"\2\2ab\3\2\2\2bj\3\2\2\2ce\5\"\22\2df\5\32\16\2ed\3\2\2\2ef\3\2\2\2fj"+
		"\3\2\2\2gj\7\6\2\2hj\7\24\2\2i[\3\2\2\2i_\3\2\2\2ic\3\2\2\2ig\3\2\2\2"+
		"ih\3\2\2\2j\31\3\2\2\2km\t\4\2\2ln\7\16\2\2ml\3\2\2\2mn\3\2\2\2n\33\3"+
		"\2\2\2op\7\30\2\2pq\5\f\7\2q\35\3\2\2\2rs\5\22\n\2sv\7\25\2\2tw\5 \21"+
		"\2uw\5\"\22\2vt\3\2\2\2vu\3\2\2\2w\37\3\2\2\2xy\5\f\7\2y!\3\2\2\2z{\7"+
		"\17\2\2{\u0080\5\26\f\2|}\7\23\2\2}\177\5\26\f\2~|\3\2\2\2\177\u0082\3"+
		"\2\2\2\u0080~\3\2\2\2\u0080\u0081\3\2\2\2\u0081\u0083\3\2\2\2\u0082\u0080"+
		"\3\2\2\2\u0083\u0084\7\20\2\2\u0084#\3\2\2\2\20\'.\61FJTY]aeimv\u0080";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}